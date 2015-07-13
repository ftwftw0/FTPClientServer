/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 16:33:53 by cdeniau           #+#    #+#             */
/*   Updated: 2015/05/02 18:41:21 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_buf_to_tmp(int rd, char *buf, char **tmp)
{
	char			*sw;

	buf[rd] = '\0';
	sw = *tmp;
	*tmp = ft_strjoin(sw, buf);
	ft_strdel(&sw);
}

void				ft_tmp_to_line(char **line, char **tmp)
{
	char			*buf;
	int				len;

	len = ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp, '\n'));
	*line = ft_strsub(*tmp, 0, len);
	buf = *tmp;
	*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	ft_strdel(&buf);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	static char		*tmp;

	rd = 0;
	if (!line || fd < 0)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(0);
	while (!(ft_strchr(tmp, '\n')) && (rd = read(fd, buf, BUFF_SIZE)) > 0)
		ft_buf_to_tmp(rd, buf, &tmp);
	if (rd < 0)
		return (-1);
	if (!(ft_strchr(tmp, '\n')))
	{
		if (!(rd))
		{
			*line = tmp;
			tmp = NULL;
			return (0);
		}
	}
	ft_tmp_to_line(line, &tmp);
	return (1);
}
