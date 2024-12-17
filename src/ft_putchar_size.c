/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:42:00 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:31:34 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_size(char c, t_flag flags)
{
	int	j;

	j = -1;
	if (!flags.dash && !flags.zero && flags.size)
		while (++j < (int)flags.size - 1)
			write(1, " ", 1);
	write(1, &c, 1);
	j = -1;
	if (flags.dash)
		while (++j < (int)flags.size - 1)
			write(1, " ", 1);
	if ((int)flags.size < 1)
		return (1);
	return (flags.size);
}

//char is undefined with "0 . # + space"
//char is defined with "dash size"
