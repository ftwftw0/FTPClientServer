/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacestrsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:00:57 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/31 18:40:18 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_splitsplitted(char const *s, char **tab)
{
	int		size;
	char	*ptr;
	int		i;
	int		words;

	ptr = NULL;
	words = 0;
	i = 0;
	while (s[i])
	{
		size = 0;
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
			ptr = (char *)&s[i];
		while (s[i] && !ft_isspace(s[i]))
		{
			i++;
			size++;
		}
		tab[words++] = ft_strsub(ptr, 0, size);
	}
	return (tab);
}

char		**ft_spacestrsplit(char const *s)
{
	char			**tab;
	int				words;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
			words++;
		while (!ft_isspace(s[i]) && s[i])
			i++;
	}
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	tab = ft_splitsplitted(s, tab);
	tab[words] = NULL;
	return (tab);
}
