/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:48:44 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:08:41 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_precision(t_flag flags, const char **t)
{
	if (**t == '.')
	{
		while (**t == '.')
		{
			flags.point++;
			(*t)++;
		}
		while (**t == '0')
			(*t)++;
		if (**t >= '0' && **t <= '9')
		{
			flags.precision += **t - '0';
			(*t)++;
		}
		while (**t >= '0' && **t <= '9')
		{
			flags.precision *= 10;
			flags.precision += (**t - '0');
			(*t)++;
		}
	}
	return (flags);
}

static t_flag	ft_size(t_flag flags, const char **t)
{
	while (**t == '0')
		(*t)++;
	if (**t >= '0' && **t <= '9')
	{
		flags.size += (**t - '0');
		(*t)++;
	}
	while (**t >= '0' && **t <= '9')
	{
		flags.size *= 10;
		flags.size += (**t - '0');
		(*t)++;
	}
	flags = ft_precision(flags, t);
	return (flags);
}

static void	ft_setup_flags(t_flag *flags)
{
	flags->space = 0;
	flags->zero = 0;
	flags->dash = 0;
	flags->plus = 0;
	flags->hashtag = 0;
	flags->point = 0;
	flags->size = 0;
	flags->precision = 0;
}

static void	ft_parseflags(const char **t, t_flag *flags)
{
	while (**t == ' ' || **t == '+' || **t == '-' || **t == '0'\
		|| **t == '#')
	{
		if (**t == ' ')
			flags->space++;
		if (**t == '0')
			flags->zero++;
		if (**t == '-')
			flags->dash++;
		if (**t == '+')
			flags->plus++;
		if (**t == '#')
			flags->hashtag++;
		(*t)++;
	}
}

t_flag	ft_parsing(const char **t)
{
	t_flag	flags;

	ft_setup_flags(&flags);
	ft_parseflags(t, &flags);
	flags = ft_size(flags, t);
	if (flags.space && flags.plus)
		flags.space = 0;
	if (flags.point && flags.zero)
		flags.zero = 0;
	if (flags.dash && flags.zero)
		flags.zero = 0;
	return (flags);
}

//so plus makes space useless
//point makes zero useless
//dash makes zero useless
