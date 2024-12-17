/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:44:27 by lorey             #+#    #+#             */
/*   Updated: 2024/10/03 15:08:53 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	back;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		back = 0;
		while (haystack[i + back] == needle[back] && (i + back) < len)
		{
			if (needle[back + 1] == '\0')
				return ((char *)haystack + i);
			back++;
		}
		i++;
	}
	return (0);
}
