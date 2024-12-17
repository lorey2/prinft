/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:02:39 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 01:16:02 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_cpy;

	lst_cpy = *lst;
	while (*lst)
	{
		lst_cpy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_cpy;
	}
	lst_cpy = *lst;
}
