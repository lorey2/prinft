/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 04:43:34 by lorey             #+#    #+#             */
/*   Updated: 2024/10/08 17:11:53 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_left(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!set[0])
		return (0);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	test_right(char const *s1, char const *set)
{
	size_t	k;
	size_t	l;

	if (!set[0])
		return (ft_strlen(s1));
	k = ft_strlen(s1);
	while (k > 0)
	{
		l = 0;
		while (set[l])
		{
			if (s1[k - 1] == set[l])
				break ;
			l++;
		}
		if (!set[l])
			break ;
		k--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	char	*result;
	size_t	count;

	if (!s1 || !set)
		return (NULL);
	i = test_left(s1, set);
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	k = test_right(s1, set);
	result = malloc(sizeof(char) * (k - i + 1));
	if (!result)
		return (NULL);
	count = 0;
	while (i < k)
		result[count++] = s1[i++];
	result[count] = '\0';
	return (result);
}
