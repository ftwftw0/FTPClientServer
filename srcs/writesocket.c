/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writesocket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 05:55:17 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 09:19:30 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	set_righthome(t_execdata *data)
{
	char	*home;
	char	*tmp;

	home = ft_getenv(data->env, "HOME");
	if (home && !ft_strncmp(home, "/nfs", 4))
	{
		tmp = ft_strjoin("/Volumes/Data", home);
		ft_setenv(data, "HOME", tmp, 1);
		free(tmp);
	}
	free(home);
}

static int	fuckdanorm(char *buff, int sock, char **env)
{
	t_execdata	*data;

	if (buff[0] == '\n')
		;
	else if (!ft_strncmp(buff, "lcd", 3))
	{
		data = (t_execdata *)malloc(sizeof(t_execdata));
		data->av = ft_spacestrsplit(buff);
		data->env = ft_tabstrdup(env);
		data->sock = sock;
		set_righthome(data);
		ft_cd(data);
		ft_freetab(&(data->av));
		ft_freetab(&(data->env));
		free(data);
	}
	else if (!ft_strncmp(buff, "lpwd", 3))
		ft_lpwd(buff);
	else if (!ft_strncmp(buff, "lls", 3))
		ft_lls(buff, env);
	else
		return (0);
	return (1);
}

static int	fuckdanorm_again(char *buff, int sock, t_execdata *data)
{
	if (!ft_strncmp(buff, "get", 3))
	{
		send(sock, buff, ft_strlen(buff), 0);
		data = (t_execdata *)malloc(sizeof(t_execdata));
		data->av = ft_spacestrsplit(buff);
		data->sock = sock;
		ft_putrecv(data);
	}
	else if (!ft_strncmp(buff, "put", 3))
	{
		data = (t_execdata *)malloc(sizeof(t_execdata));
		data->av = ft_spacestrsplit(buff);
		data->sock = sock;
		send(data->sock, "put ", 4, 0);
		send(data->sock, data->av[1], ft_strlen(data->av[1]), 0);
		send(data->sock, "\n", 1, 0);
		ft_put(data);
	}
	else
		return (0);
	recv(sock, buff, BUFF_SIZE, 0);
	ft_freetab(&(data->av));
	free(data);
	return (1);
}

static void	commandtoserver(char *buff, int sock)
{
	int			success;
	int			ret;

	success = 0;
	send(sock, buff, BUFF_SIZE, 0);
	if ((ret = recv(sock, buff, BUFF_SIZE, 0)) > 0)
	{
		buff[ret] = '\0';
		if (buff[0] != '\033')
			success = 1;
		ft_putstr(buff);
		while (buff[ret - 1] != '\0' &&
			(ret = recv(sock, buff, BUFF_SIZE, 0)))
		{
			buff[ret] = '\0';
			ft_putstr(buff);
		}
		if (success)
			ft_putstr("\033[32mSUCCESS\033[0m\n");
	}
}

void		writesocket(int sock, char **env)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;

	while (1)
	{
		getcwd(buff, BUFF_SIZE);
		showprompt(buff);
		ft_bzero(buff, BUFF_SIZE);
		if ((ret = read(0, buff, BUFF_SIZE)) <= 0 ||
			!ft_strcmp(buff, "quit\n"))
			break ;
		if (fuckdanorm(buff, sock, env) == 0 &&
			fuckdanorm_again(buff, sock, NULL) == 0)
			commandtoserver(buff, sock);
	}
	ft_putstr("-- Interrupting connection. --\n");
}
