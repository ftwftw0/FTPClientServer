/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:34:41 by flagoutt          #+#    #+#             */
/*   Updated: 2015/01/14 18:34:42 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap(void *ptra, void *ptrb)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	swap;

	a = (unsigned char *)ptra;
	b = (unsigned char *)ptrb;
	swap = *a;
	*a = *b;
	*b = swap;
}
