/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:45:01 by lorey             #+#    #+#             */
/*   Updated: 2024/10/23 01:10:17 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_type(int count, const char **format, va_list args)
{
	t_flag	flags;

	flags = ft_parsing(format);
	if (**format == 'd')
		count += ft_putnbr_size(va_arg(args, int), flags);
	else if (**format == 'c')
		count += ft_putchar_size(va_arg(args, int), flags);
	else if (**format == 'i')
		count += ft_putnbr_size(va_arg(args, int), flags);
	else if (**format == 's')
		count += ft_putstr_size(va_arg(args, char *), flags);
	else if (**format == 'p')
		count += ft_print_addr_size(va_arg(args, void *), flags);
	else if (**format == 'u')
		count += ft_putnbr_u_size(va_arg(args, unsigned int), flags);
	else if (**format == '%')
		count += write(1, "%", 1);
	else if (**format == 'x')
		count += ft_putnbr_x_size(va_arg(args, unsigned int), 0, flags);
	else if (**format == 'X')
		count += ft_putnbr_x_size(va_arg(args, unsigned int), 1, flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count = ft_arg_type(count, &format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	int	i;

	i = ft_printf("%X", 42);
	ft_printf("%i", i);
	write(1, "\n", 1);
	printf("%X", 42);
}*/
