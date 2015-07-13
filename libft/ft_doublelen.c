/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublelen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 06:11:30 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/03 12:51:59 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_doublelen(double n)
{
	size_t		len;
	double		f;

	len = 1;
	f = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	n = f - (long int)f;
	while (n != 0)
	{
		n = (n * 10);
		n -= (int)n;
		len++;
	}
	return (len);
}
