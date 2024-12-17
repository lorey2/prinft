/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:26:49 by lorey             #+#    #+#             */
/*   Updated: 2024/10/24 17:27:10 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

# if defined(__linux__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
# endif

typedef struct s_flags
{
	int			space;
	int			zero;
	int			dash;
	int			plus;
	int			hashtag;
	int			point;
	size_t		size;
	size_t		precision;
}				t_flag;

int		ft_putnbr_size(int i, t_flag flags);
int		ft_putchar_size(char c, t_flag flags);
int		ft_putstr_size(char *s, t_flag flags);
int		ft_print_addr_size(void *addr, t_flag flags);
int		ft_putnbr_x_size(unsigned int nbr, int capitalize, t_flag flags);
int		ft_printf(const char *format, ...);
int		ft_putnbr_u_size(unsigned int n, t_flag flags);
t_flag	ft_parsing(const char **t);

#endif
