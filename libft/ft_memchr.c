/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:40:24 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/12 15:42:34 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;
	char			*new;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	new = 0;
	while (i < n && new == 0)
	{
		if (str[i] == ((char)c))
			new = &(str[i]);
		i++;
	}
	return (new);
}
