/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 17:07:34 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 05:59:28 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	putusage(void)
{
	ft_putendl_fd("Usage 'put <file>'.", 2);
}

static char	*setcorrectpath(char *name, char *buff)
{
	if (!buff)
		buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	if ((name[0] == '/' || name[0] == '.') &&
		ft_strncmp(name, "/Volumes", 8) &&
		ft_strncmp(name, "/nfs", 4))
		;
	else if (name[0] == '~')
		;
	else
	{
		getcwd(buff, BUFF_SIZE);
		ft_strcat(buff, "/");
		ft_strcat(buff, name);
	}
	return (buff);
}

static void	putdafile(int size, int fd, int sock)
{
	char		*src;
	int			ret;

	ret = size;
	usleep(10000);
	ret = htonl(ret);
	send(sock, &ret, 4, 0);
	ft_putstr_fd("Size sent!\n", 2);
	src = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0);
	if (src == (caddr_t)(-1))
		ft_putstr_fd("Mmap error for inputs.", 2);
	if (send(sock, src, size, 0) == -1)
		ft_putstr_fd("\033[31mERROR : Transfer failed.\033[0m\n", 2);
	else
		ft_putstr_fd("\033[32mSUCCESS\033[0m\n", 2);
	munmap(src, size);
}

int			ft_put(t_execdata *data)
{
	struct stat filestat;
	char		buff[BUFF_SIZE];
	int			fd;
	int			ret;

	if (!(data->av[1]))
	{
		putusage();
		return (0);
	}
	setcorrectpath(data->av[1], (char *)buff);
	if ((fd = open(buff, O_RDONLY)) != -1)
	{
		ft_putstr_fd("Beginning file transfer.", 2);
		fstat(fd, &filestat);
		putdafile((int)(filestat.st_size), fd, data->sock);
		close(fd);
	}
	else
	{
		ft_putstr_fd("File does not exists or is inaccessible.\n", 2);
		ret = htonl(fd);
		send(data->sock, &ret, 4, 0);
	}
	return (1);
}
