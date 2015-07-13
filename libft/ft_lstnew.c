/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:55:36 by flagoutt          #+#    #+#             */
/*   Updated: 2015/03/09 15:42:22 by flagoutt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		exit(0);
	if (content)
	{
		if ((lst->content = (void *)malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	else
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	lst->next = NULL;
	return (lst);
}
