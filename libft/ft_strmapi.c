/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 04:10:34 by lorey             #+#    #+#             */
/*   Updated: 2024/10/05 04:21:39 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (0);
	while (s[++i])
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
