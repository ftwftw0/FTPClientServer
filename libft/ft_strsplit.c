/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 16:14:37 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/02 18:41:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] || s[i - 1] != c)
			j++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	l = ft_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * l + 1);
	while (i < l)
	{
		j = 0;
		while (*s && *s == c)
			s += 1;
		while (*(s + j) && *(s + j) != c)
			j++;
		*str++ = ft_strsub(s, 0, j);
		s += j;
		i++;
	}
	*str = NULL;
	return (str - l);
}
