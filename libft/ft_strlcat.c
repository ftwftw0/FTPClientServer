/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 13:33:06 by flagoutt          #+#    #+#             */
/*   Updated: 2014/11/21 15:18:36 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			k;
	size_t			all;

	i = ft_strlen(s1);
	k = 0;
	if (!s1 || !s2)
		return (0);
	all = ft_strlen(s1) + ft_strlen(s2);
	if (n <= i)
		return (n + ft_strlen(s2));
	while (i < n - 1 && s2[k])
		s1[i++] = s2[k++];
	s1[i] = '\0';
	return (all);
}
