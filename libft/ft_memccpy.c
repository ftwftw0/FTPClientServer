/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:38:58 by flagoutt          #+#    #+#             */
/*   Updated: 2014/11/17 16:43:06 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	if (!s2 || !s1)
		return (NULL);
	tmp = s1;
	tmp2 = s2;
	while (n--)
	{
		if (*tmp2 == c)
		{
			*tmp++ = *tmp2++;
			return (tmp);
		}
		*tmp++ = *tmp2++;
	}
	return (NULL);
}
