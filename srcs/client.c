/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:09:42 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 07:12:25 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int			create_client(char *addr, int port)
{
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					sock;

	if (!(protocol = getprotobyname("tcp")))
		return (0);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Connect error.", 2);
		return (0);
	}
	return (sock);
}

static void	usage(char *str)
{
	printf("Usage: %s <address> <port>\n", str);
	exit(-1);
}

void		showreturnfromserver(int sock)
{
	char	buff[BUFF_SIZE];
	int		ret;

	ret = read(sock, buff, BUFF_SIZE);
	ft_putendl(buff);
}

int			main(int argc, char **argv, char **env)
{
	int		port;
	int		sock;

	if (argc != 3 || !ft_isnumber(argv[2]))
		usage(argv[0]);
	port = ft_atoi(argv[2]);
	if (!(sock = create_client(argv[1], port)))
	{
		ft_putendl_fd("Error creating client.", 2);
		return (-1);
	}
	welcome(sock, argv[1], 1);
	writesocket(sock, env);
	goodbye(sock, argv[1], 1);
	close(sock);
	return (0);
}
