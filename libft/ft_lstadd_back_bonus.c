/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:41:36 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 00:56:33 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_el)
{
	t_list	*last;

	last = *lst;
	if (*lst)
	{
		while (last->next)
			last = last->next;
		last->next = new_el;
	}
	else
		*lst = new_el;
}
