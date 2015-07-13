/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:58:09 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/12 02:33:36 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
**		ABOUT EXECBI :
**	Used to execute those built-ins :
**				- env
**				- setenv
**				- unsetenv
**				- exit
**				- env
**				- pid
*/

static void	execunsetenv(t_execdata *data)
{
	int i;

	i = 1;
	while (data->av[i])
	{
		ft_unsetenv(data, data->av[i++]);
		i++;
	}
}

static void	execsetenv(t_execdata *data)
{
	char	*buff;
	char	*ptr;
	int		i;

	i = 1;
	while (data->av[i] && (ptr = ft_strchr(data->av[i], '=')))
	{
		buff = ft_strndup(data->av[i], ptr - data->av[i]);
		ft_setenv(data, buff, ptr + 1, 1);
		free(buff);
		i++;
	}
	if (!ptr)
		ft_putendl_fd("Bad environment variable format.\
		(use: setenv VAR=VALUE) [...]", 2);
}

int			execbi(char *str, t_execdata *data)
{
	if (!ft_strcmp(str, "env"))
		ft_env(data);
	else if (!ft_strcmp(str, "export") ||
			!ft_strcmp(str, "setenv"))
		execsetenv(data);
	else if (!ft_strcmp(str, "unsetenv"))
		execunsetenv(data);
	else if (!ft_strcmp(str, "pwd"))
		ft_pwd(data);
	else if (!ft_strcmp(str, "cd"))
		ft_cd(data);
	else if (!ft_strcmp(str, "put"))
		ft_putrecv(data);
	else if (!ft_strcmp(str, "get"))
		ft_put(data);
	else if (!ft_strcmp(str, "quit"))
	{
		ft_deinit(data);
		exit(0);
	}
	else
		return (0);
	return (1);
}
