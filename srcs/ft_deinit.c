/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 18:36:00 by flagoutt          #+#    #+#             */
/*   Updated: 2015/06/11 22:00:20 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int ft_deinit(t_execdata *data)
{
	if (data != NULL)
	{
		ft_freetab(&(data->av));
		ft_freetab(&(data->env));
		free(data);
	}
	return (1);
}
