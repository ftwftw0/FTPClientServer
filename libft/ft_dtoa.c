/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:08:44 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:40:38 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_tobecontinued(char *str,
								unsigned long int n,
								int *i,
								int div)
{
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[*i] = (n / div) + 48;
		n %= div;
		div /= 10;
		(*i)++;
	}
	return (str);
}

static char		*integerparttoa_double(double n)
{
	int		i;
	char	*str;
	int		div;

	i = 0;
	div = 1;
	if (!(str = (char *)malloc(sizeof(char) * ft_doublelen(n) + 1)))
		exit(0);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	str = ft_tobecontinued(str, (unsigned long int)n, &i, div);
	str[i] = '\0';
	return (str);
}

char			*ft_dtoa(double i, int j)
{
	double	l;
	char	*str;
	char	*join;
	char	*end;

	str = integerparttoa_double(i);
	l = i - (double)((unsigned long int)i);
	l = (l < 0.0) ? l * -1.0 : l;
	if ((int)j == 0)
		return (str);
	end = ft_strjoin(str, ".");
	free(str);
	while (j > 0)
	{
		l = l * 10.0;
		str = ft_itoa(((int)l) % 10);
		join = ft_strjoin(end, str);
		free(end);
		end = ft_strdup(join);
		free(str);
		free(join);
		j--;
	}
	return (end);
}
