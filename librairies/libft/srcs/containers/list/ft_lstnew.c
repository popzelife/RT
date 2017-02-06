/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:00:12 by qfremeau          #+#    #+#             */
/*   Updated: 2016/02/11 15:43:48 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*ptr_content;

	ptr_content = ft_memalloc(content_size + 1);
	if (!ptr_content)
		return (NULL);
	if (content == NULL)
	{
		ptr_content = NULL;
		content_size = 0;
	}
	else
		ptr_content = ft_memcpy(ptr_content, content, content_size);
	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list != (t_list *)NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = ptr_content;
	}
	return (list);
}
