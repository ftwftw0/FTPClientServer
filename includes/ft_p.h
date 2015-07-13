/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 15:14:56 by flagoutt          #+#    #+#             */
/*   Updated: 2015/07/13 08:28:19 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <netdb.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>

typedef struct	s_execdata
{
	char		**env;
	char		**av;
	int			sock;
}				t_execdata;

void			showprompt(char *currentdir);
void			welcome(int id, char *addr, int fd);
void			goodbye(int id, char *addr, int fd);
void			showid(int id, int fd);
int				create_client(char *addr, int port);
int				create_server(int port);
int				launchcommands(char *buff, t_execdata *child);
int				launchprogram(t_execdata *data, t_execdata *tmp);
int				initclientenv(t_execdata **child, char **env);
char			**ft_tabstrdup(char **thetab);
int				execbi(char *str, t_execdata *data);
char			*ft_getenv(char **env, char *elem);
int				ft_env(t_execdata *data);
int				ft_setenv(t_execdata *data, const char *name,
							const char *value, int overwrite);
int				childexec(t_execdata *data, t_execdata *tmp);
int				ft_unsetenv(t_execdata *data, const char *name);
int				ft_cd(t_execdata *data);
int				ft_deinit(t_execdata *data);
int				showstringtab(char **strtab);
int				ft_put(t_execdata *data);
int				ft_putrecv(t_execdata *data);
void			ft_pwd(t_execdata *data);
void			ft_lpwd(char *buff);
void			ft_lls(char *buff, char **env);
void			readsocket(int clientsock, char **env);
void			writesocket(int sock, char **env);

#endif
