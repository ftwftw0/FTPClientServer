/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:07:57 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/14 15:51:02 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int s2len;

	i = -1;
	if (ft_strlen(s2) == 0)
		return (s1);
	else if (ft_strlen(s1) < ft_strlen(s2) || ft_strlen(s2) > n)
		return (NULL);
	s2len = (ft_strlen(s2) > n) ? n : ft_strlen(s2);
	while (s1[++i + s2len - 1] && i + s2len <= n)
		if (ft_memcmp(s1 + i, s2, s2len) == 0)
			return (s1 + i);
	return (NULL);
}
