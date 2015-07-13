/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 03:56:25 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/12 04:28:27 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void ft_lls(char *buff, char **env)
{
	t_execdata *data;

	data = (t_execdata *)malloc(sizeof(t_execdata));
	data->env = env;
	launchcommands(buff + 1, data);
	ft_freetab(&(data->av));
	free(data);
}
