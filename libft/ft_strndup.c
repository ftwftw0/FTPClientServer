/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:38:22 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:44:58 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = (ft_strlen(s1) >= n) ? n : ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		exit(0);
	ft_strncpy(s2, s1, n);
	return (s2);
}
