/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchprograms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 19:39:05 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 02:47:09 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void		set_righthome(t_execdata *data)
{
	char	*home;
	char	*tmp;

	home = ft_getenv(data->env, "HOME");
	if (!ft_strncmp(home, "/nfs", 4))
	{
		tmp = ft_strjoin("/Volumes/Data", home);
		ft_setenv(data, "HOME", tmp, 1);
		free(tmp);
	}
	free(home);
}

int			launchprogram(t_execdata *data, t_execdata *tmp)
{
	pid_t		shell;
	int			ret;

	if (data->av[0] != NULL)
	{
		if ((ret = ((tmp != NULL) ? execbi(tmp->av[0], tmp) :
					execbi(data->av[0], data))) == 0)
		{
			shell = fork();
			if (shell > 0)
				wait(&shell);
			else if (shell == 0 && childexec(data, tmp) == 1)
				return (0);
		}
		else if (ret == 1)
			return (2);
	}
	ft_freetab(&(data->av));
	return (1);
}

int			initclientenv(t_execdata **child, char **env)
{
	if (((*child) = (t_execdata *)malloc(sizeof(t_execdata))) == NULL)
		return (0);
	(*child)->env = ft_tabstrdup(env);
	set_righthome((*child));
	(*child)->av = NULL;
	return (1);
}

int			launchcommands(char *buff, t_execdata *child)
{
	char		**commands;
	int			i;

	commands = ft_strsplit(buff, ';');
	i = -1;
	while (commands[++i])
	{
		child->av = ft_spacestrsplit(commands[i]);
		if (launchprogram(child, NULL) == 0)
			return (0);
		ft_freetab(&(child->av));
	}
	ft_freetab(&commands);
	return (1);
}
