/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 02:32:36 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/12 04:29:09 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void ft_pwd(t_execdata *data)
{
	char *pwd;
	char *tmp;

	pwd = getcwd(NULL, BUFF_SIZE);
	tmp = ft_getenv(data->env, "HOME");
	send(data->sock, pwd + ft_strlen(tmp), ft_strlen(pwd + ft_strlen(tmp)), 0);
	send(data->sock, "/\n", 2, 0);
	send(data->sock, "\0", 1, 0);
	free(tmp);
	free(pwd);
}

void ft_lpwd(char *buff)
{
	getcwd(buff, BUFF_SIZE);
	ft_putendl(buff);
}
