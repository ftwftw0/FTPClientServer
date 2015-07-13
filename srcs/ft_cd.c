/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 19:19:48 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 06:51:56 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void		absolute_path(t_execdata *data, char *path)
{
	char *buff;
	char *home;

	buff = ft_strnew(BUFF_SIZE);
	getcwd(buff, BUFF_SIZE);
	home = ft_getenv(data->env, "HOME");
	if (ft_strlen(buff) > ft_strlen(home) && chdir(buff) != -1)
	{
		ft_setenv(data, "OLDPWD", buff, 1);
		getcwd(buff, BUFF_SIZE);
		ft_setenv(data, "PWD", buff, 1);
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory:", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
	free(buff);
	free(home);
}

static void		relative_path(t_execdata *data, char *path)
{
	char *buff;
	char *oldpwd;
	char *home;

	oldpwd = ft_strnew(BUFF_SIZE);
	getcwd(oldpwd, BUFF_SIZE);
	home = ft_getenv(data->env, "HOME");
	if (oldpwd[ft_strlen(oldpwd) - 1] == '/')
		buff = ft_strjoin(oldpwd, path);
	else
		buff = ft_strtrijoin(oldpwd, "/", path);
	if (ft_strlen(buff) > ft_strlen(home) + 3 && chdir(buff) != -1)
	{
		ft_setenv(data, "OLDPWD", oldpwd, 1);
		getcwd(buff, BUFF_SIZE);
		ft_setenv(data, "PWD", buff, 1);
	}
	else
		ft_triputstr("cd: no suck file or directory:", path, "\n");
	if (buff)
		free(buff);
	if (home)
		free(home);
	if (oldpwd)
		free(oldpwd);
}

static void		home_path(t_execdata *data, char *path)
{
	char *buff;
	char *oldpwd;
	char *home;

	oldpwd = ft_strnew(BUFF_SIZE);
	getcwd(oldpwd, BUFF_SIZE);
	if ((home = ft_getenv(data->env, "HOME")) != NULL)
	{
		buff = (home[ft_strlen(home) - 1] == '/') ?
			ft_strjoin(home, path + 2) :
			ft_strjoin(home, path + 1);
		if (ft_strlen(buff) > ft_strlen(home) && chdir(buff) != -1)
		{
			ft_setenv(data, "OLDPWD", oldpwd, 1);
			getcwd(buff, BUFF_SIZE);
			ft_setenv(data, "PWD", buff, 1);
		}
		else
			ft_triputstr("cd: no such file or directory:", path, "\n");
		free(home);
		free(buff);
	}
	else
		ft_putstr("cd: no HOME environment variable.\n");
	free(oldpwd);
}

static void		previous_path(t_execdata *data)
{
	char *oldpwd;
	char buff[BUFF_SIZE + 1];

	if ((oldpwd = ft_getenv(data->env, "OLDPWD")) == NULL)
		ft_putendl("No previous path, or no OLDPWD environment variable.");
	else
	{
		getcwd(buff, BUFF_SIZE);
		absolute_path(data, oldpwd);
		ft_setenv(data, "OLDPWD", buff, 1);
		ft_setenv(data, "PWD", oldpwd, 1);
		free(oldpwd);
	}
}

int				ft_cd(t_execdata *data)
{
	if (data->av[1] == NULL)
		home_path(data, "~/");
	else if (data->av[1][0] == '/')
		absolute_path(data, data->av[1]);
	else if (data->av[1][0] == '~')
		home_path(data, data->av[1]);
	else if (!ft_strcmp(data->av[1], "-"))
		previous_path(data);
	else
		relative_path(data, data->av[1]);
	return (1);
}
