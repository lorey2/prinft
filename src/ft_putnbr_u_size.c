/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:30:24 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:05:31 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_u(unsigned int i)
{
	int	counter;

	counter = 0;
	if (i == 0)
		++counter;
	while (i != 0)
	{
		counter++;
		i /= 10;
	}
	return (counter);
}

static void	ft_zero_dash_u(unsigned int i, t_flag flags, int nbrwith_prec)
{
	int	j;

	j = -1;
	if (flags.zero)
		while (++j < (int)flags.size - nbrwith_prec)
			write(1, "0", 1);
	j = ft_count_u(i) - 1;
	while (++j < (int)flags.precision)
		write(1, "0", 1);
	ft_putnbr_fd(i, 1);
	j = -1;
	if (flags.dash)
		while (++j < (int)flags.size - nbrwith_prec)
			write(1, " ", 1);
}

int	ft_putnbr_u_size(unsigned int i, t_flag flags)
{
	int	nbrwith_prec;
	int	j;

	j = -1;
	if (flags.point && !flags.precision && i == 0)
		return (ft_putstr_size(" ", flags));
	if ((int)flags.precision > ft_count_u(i))
		nbrwith_prec = (unsigned int)flags.precision;
	else
		nbrwith_prec = ft_count_u(i);
	if (!flags.dash && !flags.zero && flags.size)
		while (++j < (int)flags.size - nbrwith_prec)
			write(1, " ", 1);
	ft_zero_dash_u(i, flags, nbrwith_prec);
	if ((int)flags.size < nbrwith_prec)
		return (nbrwith_prec);
	return (flags.size);
}

//"+ space #" not defined
//the rest is
