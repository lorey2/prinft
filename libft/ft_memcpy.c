/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:57:09 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 16:12:06 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == 0 && src == 0 && n > 0)
		return (0);
	i = 0;
	while (++i < n + 1)
		*(unsigned char *)(dst + i - 1) = *(unsigned char *)(src + i - 1);
	return (dst);
}
