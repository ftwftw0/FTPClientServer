/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:21:52 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 04:48:39 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		create_server(int port)
{
	struct protoent		*protocol;
	struct sockaddr_in	sin;
	int					sock;

	if (!(protocol = getprotobyname("tcp")))
		return (0);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Bind error.", 2);
		return (0);
	}
	listen(sock, 4242);
	return (sock);
}

void	usage(char *str)
{
	printf("Usage: %s <validport>\n", str);
	exit(-1);
}

void	clientconnected(int clientsock, char **env)
{
	dup2(clientsock, STDOUT_FILENO);
	readsocket(clientsock, env);
	close(clientsock);
	exit(0);
}

int		main(int argc, char **argv, char **env)
{
	struct sockaddr_in	csin;
	unsigned int		csinlen;
	int					sock;
	int					clientsock;
	pid_t				client;

	if (argc != 2)
		usage(argv[0]);
	sock = create_server(ft_atoi(argv[1]));
	if (!ft_isnumber(argv[1]) || !sock)
		usage(argv[0]);
	while (1)
	{
		if ((clientsock = accept(sock, (struct sockaddr *)&csin, &csinlen)) > 0)
		{
			if ((client = fork()) == 0)
				clientconnected(clientsock, env);
		}
		else
			ft_putendl_fd("   --- Connection failed ---", 2);
	}
	close(sock);
	return (0);
}
