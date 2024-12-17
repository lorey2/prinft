/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:26 by lorey             #+#    #+#             */
/*   Updated: 2024/10/19 15:38:42 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursive(unsigned int n, int fd)
{
	char	one_char;

	if (n != 0)
	{
		one_char = (n % 10) + '0';
		n /= 10;
		recursive(n, fd);
		write(fd, &one_char, 1);
	}
}

void	ft_putnbr_fd(long n, int fd)
{
	unsigned int	temp;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			temp = -n;
			recursive(temp, fd);
		}
		else
			recursive(n, fd);
	}
}
