/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrecv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 03:42:11 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 09:12:01 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int	getdafile(int size, int fd, int sock)
{
	char		buff[BUFF_SIZE];
	char		*dst;
	char		*ptr;
	int			ret;

	if ((dst = mmap(NULL, size, PROT_WRITE,
					MAP_SHARED, fd, 0)) == (caddr_t)(-1))
		ft_putendl_fd("Mmap error for output.", 2);
	ptr = dst;
	while (ptr - dst < (long)size)
	{
		if ((ret = recv(sock, buff, BUFF_SIZE, 0)) == -1)
			break ;
		memcpy(ptr, buff, ret);
		ptr += ret;
	}
	if (ret == -1)
		ft_putstr_fd("\033[31mERROR : Transfer failed.\033[0m\n", 2);
	else
		ft_putstr_fd("\033[32mSUCCESS\033[0m\n", 2);
	munmap(dst, size);
	return (ret);
}

int			ft_putrecv(t_execdata *data)
{
	int			fd;
	int			size;

	recv(data->sock, &size, 4, 0);
	if ((size = ntohl(size)) == -1)
	{
		ft_putstr_fd("File does not exists or is inaccessible.\n", 2);
		return (0);
	}
	else
	{
		if ((fd = open(data->av[1], O_RDWR | O_CREAT | O_TRUNC, 0777)) == -1)
			return (0);
		ft_putstr_fd("File size : ", 2);
		ft_putnbr_fd(size, 2);
		ft_putstr_fd("\nStarting file transfer.\n", 2);
		lseek(fd, size - 1, SEEK_SET);
		write(fd, "\0", 1);
		getdafile(size, fd, data->sock);
		close(fd);
	}
	return (1);
}
