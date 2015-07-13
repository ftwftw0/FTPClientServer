/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 17:00:39 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/01 15:08:36 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void tryexec(const char *path, char *const argv[], char *const envp[])
{
	execve(path, argv, envp);
}

static void	intopaths(t_execdata *data, t_execdata *tmp)
{
	char	*strpaths;
	char	**paths;
	int		i;

	if ((strpaths = ft_getenv(data->env, "PATH")) != NULL)
	{
		paths = ft_strsplit(strpaths, ':');
		i = -1;
		if (tmp)
			data = tmp;
		while (paths[++i])
		{
			free(strpaths);
			strpaths = ft_strtrijoin(paths[i], "/", data->av[0]);
			tryexec(strpaths, data->av, data->env);
			free(paths[i]);
		}
		free(paths);
	}
	free(strpaths);
}

static void	abspath(t_execdata *data, t_execdata *tmp)
{
	char *path;
	char *pwd;

	if ((pwd = ft_getenv(data->env, "PWD")))
	{
		free(pwd);
		if (tmp)
		{
			if (tmp->av[0][0] == '/')
				path = ft_strjoin(pwd, tmp->av[0]);
			else
				path = ft_strjoin(pwd, tmp->av[0] + 1);
			tryexec(path, tmp->av, tmp->env);
		}
		else
		{
			if (data->av[0][0] == '/')
				path = ft_strjoin(pwd, data->av[0]);
			else
				path = ft_strjoin(pwd, data->av[0] + 1);
			tryexec(path, data->av, data->env);
		}
		free(path);
	}
	tryexec(data->av[0], data->av, data->env);
}

static void homepath(t_execdata *data, t_execdata *tmp)
{
	char *buff;
	char *home;

	if ((home = ft_getenv(data->env, "HOME")) != NULL)
	{
		if (tmp)
		{
			if (home[ft_strlen(home) - 1] == '/')
				home[ft_strlen(home) - 1] = '\0';
			buff = ft_strjoin(home, data->av[0] + 1);
			tryexec(buff, tmp->av, tmp->env);
		}
		else
		{
			if (home[ft_strlen(home) - 1] == '/')
				home[ft_strlen(home) - 1] = '\0';
			buff = ft_strjoin(home, data->av[0] + 1);
			tryexec(buff, data->av, data->env);
		}
		free(home);
		free(buff);
	}
	else
		ft_putendl_fd("cd: no HOME environment variable.", 2);
}

int			childexec(t_execdata *data, t_execdata *tmp)
{
	if (tmp)
	{
		if ((tmp->av[0][0] == '/' || tmp->av[0][0] == '.') &&
			ft_strncmp(tmp->av[0], "/Volumes", 8) &&
			ft_strncmp(tmp->av[0], "/nfs", 4))
			abspath(data, tmp);
		else if (tmp->av[0][0] == '~')
			homepath(data, tmp);
		else
			intopaths(data, tmp);
	}
	else
	{
		if ((data->av[0][0] == '/' || data->av[0][0] == '.') &&
			ft_strncmp(data->av[0], "/Volumes", 8) &&
			ft_strncmp(data->av[0], "/nfs", 4))
			abspath(data, tmp);
		else if (data->av[0][0] == '~')
			homepath(data, tmp);
		else
			intopaths(data, tmp);
	}
	ft_putstr("\033[31mERROR : Program not found.\n\033[0m");
	return (1);
}
