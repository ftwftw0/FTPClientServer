/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:00:48 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/15 13:15:46 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char	*ft_getenv(char **env, char *elem)
{
	char	*uppername;
	char	*ptr;
	char	*value;
	int		i;
	int		len;

	i = -1;
	value = NULL;
	len = ft_strlen(elem);
	uppername = ft_strdup(elem);
	ft_strupper(uppername);
	while (env[++i])
	{
		if (!ft_strncmp(env[i], elem, len) ||
			!ft_strncmp(env[i], uppername, len))
		{
			if ((ptr = ft_strchr(env[i], '=')))
				value = ft_strndup(ptr + 1, ft_strlen(ptr));
		}
	}
	free(uppername);
	return (value);
}
