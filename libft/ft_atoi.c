/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:32:06 by lorey             #+#    #+#             */
/*   Updated: 2024/10/03 10:35:08 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	number = 0;
	neg = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'\
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number += (str[i] - '0');
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			number *= 10;
		i++;
	}
	return (number *= neg);
}
