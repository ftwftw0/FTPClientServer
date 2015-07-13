/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:01:12 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:44:09 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		exit(0);
	ft_strcpy(s2, s1);
	return (s2);
}
