/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copystringtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:34:29 by flagoutt          #+#    #+#             */
/*   Updated: 2015/05/10 20:57:40 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
**  Tab has to end with a null value, to know when to stop
*/
char **ft_tabstrdup(char **thetab)
{
	char	**new;
	int		i;

	i = 0;
	while (thetab[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	new[i] = NULL;
	i--;
	while (i >= 0)
	{
		new[i] = ft_strdup(thetab[i]);
		i--;
	}
	return (new);
}
