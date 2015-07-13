/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 18:43:08 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/15 14:29:29 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char			**reallocenv(char **env, int envsize)
{
	char **newenv;

	newenv = (char **)malloc(sizeof(char *) * (envsize + 2));
	envsize = -1;
	while (env[++envsize])
		newenv[envsize] = env[envsize];
	newenv[envsize] = NULL;
	newenv[envsize + 1] = NULL;
	free(env);
	return (newenv);
}

static void		putvariable(char *dst, const char *name, const char *value)
{
	ft_strcpy(dst, name);
	ft_strcat(dst, "=");
	ft_strcat(dst, value);
}

static int		setenvsplitted(t_execdata *data, char **uppername,
								const char *name, int *len)
{
	int envsize;

	(*uppername) = ft_strdup(name);
	ft_strupper((*uppername));
	envsize = 0;
	while (data->env[envsize])
		envsize++;
	if (!data->env)
		return (-1);
	(*len) = ft_strlen(name);
	return (envsize);
}

int				ft_setenv(t_execdata *data, const char *name,
					const char *value, int overwrite)
{
	char	*uppername;
	int		envsize;
	int		len;
	int		i;

	i = 0;
	envsize = setenvsplitted(data, &uppername, name, &len);
	while (i < envsize && ft_strncmp(name, data->env[i], len) &&
							ft_strncmp(uppername, data->env[i], len))
		i++;
	if (i < envsize && overwrite)
	{
		free(data->env[i]);
		data->env[i] = ft_strnew(sizeof(char) * (len + ft_strlen(value) + 2));
		putvariable(data->env[i], name, value);
	}
	else if (i == envsize)
	{
		data->env = reallocenv(data->env, envsize);
		data->env[envsize] = ft_strnew(sizeof(char) *
										(len + ft_strlen(value) + 2));
		putvariable(data->env[envsize], name, value);
	}
	free(uppername);
	return (0);
}
