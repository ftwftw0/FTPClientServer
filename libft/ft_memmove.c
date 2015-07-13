/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:49:19 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:43:22 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*s2temp;

	if (!(s2temp = (char *)malloc(n + 1)))
		exit(0);
	ft_memcpy(s2temp, s2, n);
	ft_memcpy(s1, s2temp, n);
	free(s2temp);
	return (s1);
}
