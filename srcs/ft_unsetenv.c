/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:14:26 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/31 19:00:02 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static char **reallocdelenv(char **env, int envsize, int index)
{
	char **newenv;

	newenv = (char **)malloc(sizeof(char *) * (envsize));
	envsize = 0;
	while (env[envsize] && envsize != index)
	{
		newenv[envsize] = env[envsize];
		envsize++;
	}
	free(env[envsize]);
	envsize++;
	while (env[envsize])
		newenv[index++] = env[envsize++];
	newenv[envsize] = NULL;
	free(env);
	return (newenv);
}

int			ft_unsetenv(t_execdata *data, const char *name)
{
	char	*uppername;
	int		envsize;
	int		len;
	int		i;

	uppername = ft_strdup(name);
	ft_strupper(uppername);
	envsize = 0;
	while (data->env[envsize])
		envsize++;
	if (!(data->env))
		return (-1);
	i = -1;
	len = ft_strlen(name);
	while (++i < envsize)
		if (!ft_strncmp(name, data->env[i], len)
			|| !ft_strncmp(uppername, data->env[i], len))
			break ;
	if (i < envsize)
		data->env = reallocdelenv(data->env, envsize, i);
	else
		ft_putendl_fd("Environment variable does not exist.", 2);
	free(uppername);
	return (0);
}
