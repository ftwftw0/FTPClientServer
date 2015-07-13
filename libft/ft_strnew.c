/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:49:43 by flagoutt          #+#    #+#             */
/*   Updated: 2014/11/14 14:49:44 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	if ((str = (char *)malloc(size + 1)))
	{
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
