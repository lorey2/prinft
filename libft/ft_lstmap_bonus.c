/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:37:43 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 02:19:33 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*list;
	void	*new_content;

	list = 0;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		element = ft_lstnew(new_content);
		if (!element)
		{
			ft_lstclear(&list, del);
			if (new_content)
				del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&list, element);
		lst = lst->next;
	}
	return (list);
}
