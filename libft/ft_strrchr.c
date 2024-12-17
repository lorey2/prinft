/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:31:02 by lorey             #+#    #+#             */
/*   Updated: 2024/10/03 12:28:36 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	backup;

	backup = -1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			backup = i;
	}
	if (backup != -1)
		return ((char *)(s + backup));
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (0);
}
