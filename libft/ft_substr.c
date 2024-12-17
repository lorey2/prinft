/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:45:41 by lorey             #+#    #+#             */
/*   Updated: 2024/10/07 15:18:11 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*send;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	send = malloc(sizeof(char) * (len + 1));
	if (!send)
		return (0);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		send[j] = s[i];
		i++;
		j++;
	}
	send[j] = '\0';
	return (send);
}
