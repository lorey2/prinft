/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:13:47 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 02:04:41 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int i)
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

static void	ft_sign_zero_dash(int i, t_flag flags, int nbrwith_prec, int sign)
{
	int	j;

	if (i < 0)
		write(1, "-", 1);
	else if (flags.plus)
		write(1, "+", 1);
	else if (flags.space)
		write(1, " ", 1);
	j = -1;
	if (flags.zero)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, "0", 1);
	j = ft_count(i) - 1;
	while (++j < (int)flags.precision)
		write(1, "0", 1);
	ft_putnbr_fd(i, 1);
	j = -1;
	if (flags.dash)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, " ", 1);
}

int	ft_putnbr_size(int i, t_flag flags)
{
	int	nbrwith_prec;
	int	sign;
	int	j;

	j = -1;
	sign = 0;
	if (flags.point && !flags.precision && i == 0)
		return (ft_putstr_size(" ", flags));
	if ((int)flags.precision > ft_count(i))
		nbrwith_prec = (int)flags.precision;
	else
		nbrwith_prec = ft_count(i);
	if (i < 0 || flags.space || flags.plus)
		sign = 1;
	if (!flags.dash && !flags.zero && flags.size)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, " ", 1);
	ft_sign_zero_dash(i, flags, nbrwith_prec, sign);
	if ((int)flags.size < nbrwith_prec + sign)
		return (nbrwith_prec + sign);
	return (flags.size);
}
// "." " " "-" "+" "#" "0"
//
//po															DONE		DONE
//sp															DONE		DONE
//da															DONE		DONE
//pl															DONE		DONE
//ze															DONE		DONE
//size															DONE		DONE
//SAME with only size
//WITH 0 - take a place WITH . is does not
//
//# is not used with d i 
//
//po sp			WORKS											DONE
//po da			WORKS											DONR
//po pl			WORKS											DONE
//po ze			ze ignored										DONE
//
//sp da			if nb neg sp ignored else sp at begining		DONE
//sp pl			sp ignored										DONE
//sp ze			if nb neg sp ignored else sp at begining		DONE
//
//da pl			WORKS											DONE
//da ze			ze ignored										DONE
//
//pl ze			if nb neg sp ignored else sp at begining		DONE
