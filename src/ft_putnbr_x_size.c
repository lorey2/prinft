/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:33:21 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:39:12 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_x(unsigned int nbr)
{
	int				count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

static void	ft_write_x(unsigned int nbr, int capitalize)
{
	char			*base;
	int				i;
	char			tab[9];

	if (capitalize == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr == 0)
		write(1, "0", 1);
	i = 0;
	while (nbr != 0)
	{
		tab[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (--i >= 0)
		write(1, &tab[i], 1);
}

static void	ft_ze_da_x(int nbr, t_flag flags, int nbrwith_prec, int capitalize)
{
	int	j;
	int	sign;

	sign = 0;
	if (flags.hashtag && nbr != 0)
		sign = 2;
	j = -1;
	if (flags.zero)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, "0", 1);
	j = ft_count_x(nbr) - 1;
	while (++j < (int)flags.precision)
		write(1, "0", 1);
	ft_write_x(nbr, capitalize);
	j = -1;
	if (flags.dash)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, " ", 1);
}

int	ft_putnbr_x_size(unsigned int nbr, int capitalize, t_flag flags)
{
	int	nbrwith_prec;
	int	sign;
	int	j;

	j = -1;
	sign = 0;
	if (flags.point && !flags.precision && nbr == 0)
		return (ft_putstr_size(" ", flags));
	if ((int)flags.precision > ft_count_x(nbr))
		nbrwith_prec = (int)flags.precision;
	else
		nbrwith_prec = ft_count_x(nbr);
	if (flags.hashtag && nbr != 0)
		sign = 2;
	if (!flags.dash && !flags.zero && flags.size)
		while (++j < (int)flags.size - (nbrwith_prec + sign))
			write(1, " ", 1);
	if (flags.hashtag && capitalize == 0 && nbr != 0)
		write(1, "0x", 2);
	if (flags.hashtag && capitalize == 1 && nbr != 0)
		write(1, "0X", 2);
	ft_ze_da_x(nbr, flags, nbrwith_prec, capitalize);
	if ((int)flags.size < nbrwith_prec + sign)
		return (nbrwith_prec + sign);
	return (flags.size);
}

//undefinded	"space, +"
//defined		"#, -, ., sizeonly, 0"
