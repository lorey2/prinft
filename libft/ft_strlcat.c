/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:36:28 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 16:14:48 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	while (++i < (dstsize - dst_len) && src[i - 1])
		dst[dst_len + i - 1] = src[i - 1];
	dst[dst_len + i - 1] = '\0';
	return (dst_len + ft_strlen(src));
}
