/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:53:08 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:40:09 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_str_point(char *s, t_flag flags)
{
	int	nb_towrite;
	int	counter;

	counter = -1;
	if (flags.precision < ft_strlen(s) && flags.point)
		nb_towrite = flags.precision;
	else
		nb_towrite = ft_strlen(s);
	if (flags.dash)
	{
		write(1, s, nb_towrite);
		while (++counter < (int)flags.size - nb_towrite)
			write(1, " ", 1);
		return (counter + nb_towrite);
	}
	if (flags.size)
	{
		while (++counter < (int)flags.size - nb_towrite)
			write(1, " ", 1);
		write(1, s, nb_towrite);
		return (counter + nb_towrite);
	}
	return (write(1, s, nb_towrite));
}

int	ft_putstr_size(char *s, t_flag flags)
{
	if (s == NULL && flags.point && flags.precision >= 6)
		return (ft_putstr_size("(null)", flags));
	if (s == NULL && flags.point)
		return (ft_putstr_size("", flags));
	if (s == NULL)
		return (ft_putstr_size("(null)", flags));
	if (flags.point || flags.size || flags.dash)
		return (ft_check_str_point(s, flags));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

//undefined "+, space, #, 0, ."
//defined "-, size"
