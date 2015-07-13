/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 15:10:05 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 05:43:11 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	showprompt(char *currentdir)
{
	ft_triputstr("\033[33m[", currentdir, "]\033[35m$\033[0m ");
}

int		showstringtab(char **strtab)
{
	int i;

	i = 0;
	if (!strtab)
		return (0);
	while (strtab[i])
		ft_putendl(strtab[i++]);
	return (1);
}

void	showid(int id, int fd)
{
	ft_putstr_fd("\033[33m[Client ", fd);
	ft_putstr_fd("\033[35m", fd);
	ft_putnbr_fd(id, fd);
	ft_putstr_fd("\033[33m ]", fd);
	ft_putstr_fd("\033[0m ", fd);
}

void	welcome(int id, char *addr, int fd)
{
	ft_putstr_fd("\n\033[32m   --- ", fd);
	if (!addr)
	{
		ft_putstr_fd("New connection. (id : ", fd);
		ft_putnbr_fd(id, fd);
		ft_putchar_fd(')', fd);
	}
	else
	{
		ft_putstr_fd("Connected to ", fd);
		ft_putstr_fd(addr, fd);
		ft_putstr_fd(".", fd);
	}
	ft_putstr_fd(" ---", fd);
	ft_putendl_fd("\033[0m ", fd);
}

void	goodbye(int id, char *addr, int fd)
{
	ft_putstr_fd("\n\033[32m   --- ", fd);
	if (!addr)
	{
		ft_putstr_fd("Closed connection. (id : ", fd);
		ft_putnbr_fd(id, fd);
		ft_putchar_fd(')', fd);
		close(fd);
	}
	else
	{
		ft_putstr_fd("Disconnected from ", fd);
		ft_putstr_fd(addr, fd);
		ft_putstr_fd(".", fd);
	}
	ft_putstr_fd(" ---", fd);
	ft_putendl_fd("\033[0m ", fd);
}
