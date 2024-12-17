/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:48:14 by lorey             #+#    #+#             */
/*   Updated: 2024/10/24 17:09:24 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_addr(unsigned long *i, char *tab)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += write(1, &tab[*i], 16 - *i);
	return (count);
}

static int	ft_bad_count(void *addr, unsigned long *i, char *tab)
{
	int				j;
	const char		hex[] = "0123456789abcdef";

	j = 15;
	*i = (unsigned long)addr;
	while (*i > 0)
	{
		tab[j--] = hex[(*i) % 16];
		*i /= 16;
	}
	while (j >= 0)
		tab[j--] = '0';
	tab[16] = '\0';
	*i = 0;
	while (tab[*i] == '0' && *i < 15)
		(*i)++;
	return (3 + (15 - *i));
}

int	ft_print_addr_size(void *addr, t_flag flags)
{
	unsigned long	i;
	char			tab[17];
	int				count;

	if (!addr)
		return (ft_putstr_size(PTRNULL, flags));
	count = ft_bad_count(addr, &i, tab);
	if (flags.dash)
	{
		ft_write_addr(&i, tab);
		while (count < (int)flags.size)
			count += write(1, " ", 1);
		return (count);
	}
	if (flags.size)
	{
		while (count < (int)flags.size)
			count += write(1, " ", 1);
		ft_write_addr(&i, tab);
		return (count);
	}
	ft_write_addr(&i, tab);
	return (count);
}

//undefined : (".", "0", "+", "#", " ")
//remaining : ("-", "size")
