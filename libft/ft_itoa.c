/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:40:58 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 17:04:29 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	full_tab(char *result, int *count, int *neg, int *n)
{
	result[*count + *neg] = '\0';
	if (*neg)
		result[0] = '-';
	while (*count > 0)
	{
		result[*count + *neg - 1] = (*n % 10) + '0';
		*n /= 10;
		(*count)--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	count = count_digits(n);
	result = malloc(sizeof(char) * (count + 1 + neg));
	if (!result)
		return (0);
	full_tab(result, &count, &neg, &n);
	return (result);
}
