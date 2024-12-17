/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:08:43 by lorey             #+#    #+#             */
/*   Updated: 2024/10/07 18:33:52 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*point;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	point = malloc(size * count);
	if (!point)
		return (0);
	while (i < count * size)
		((unsigned char *)point)[i++] = 0;
	return (point);
}
