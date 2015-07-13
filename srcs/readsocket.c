/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readsocket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 04:43:57 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 05:43:24 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void		sethomeroot(char **env)
{
	char	*ptr;
	int		i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "HOME", 4))
		{
			free(env[i]);
			ptr = getcwd(NULL, BUFF_SIZE);
			env[i] = ft_strjoin("HOME=", ptr);
			free(ptr);
			return ;
		}
	}
}

static int	getreceivedinfo(int clientsock, char *buff, int stdout, int ret)
{
	char			*ptr;

	showid(clientsock, stdout);
	ptr = &buff[ret];
	while ((ret = recv(clientsock, ptr, BUFF_SIZE, MSG_DONTWAIT)) > 0)
		ptr = &ptr[ret];
	ft_putnbr_fd(ft_strlen(buff), stdout);
	ft_putstr_fd(" bytes received : ", stdout);
	ft_putstr_fd(buff, stdout);
	return (ret);
}

void		readsocket(int clientsock, char **env)
{
	t_execdata		*clientdatas;
	char			buff[BUFF_SIZE];
	int				stdout;
	int				ret;

	initclientenv(&clientdatas, env);
	sethomeroot(clientdatas->env);
	stdout = open("/dev/tty", O_RDWR);
	welcome(clientsock, NULL, stdout);
	while (1)
	{
		getcwd(buff, BUFF_SIZE);
		ft_bzero(buff, BUFF_SIZE);
		if ((ret = (recv(clientsock, buff, BUFF_SIZE, 0))) <= 0)
			break ;
		if (getreceivedinfo(clientsock, buff, stdout, ret) == -1 ||
			buff[0] != '\n')
		{
			clientdatas->sock = clientsock;
			if ((launchcommands(buff, clientdatas)) == 0)
				exit(0);
		}
		ft_putchar('\0');
	}
	goodbye(clientsock, NULL, stdout);
}
