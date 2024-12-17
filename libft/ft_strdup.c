/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:22:36 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 17:26:47 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*point;

	i = 0;
	point = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!point)
		return (0);
	while (++i <= ft_strlen(s1))
		point[i - 1] = s1[i - 1];
	point[i - 1] = '\0';
	return (point);
}
