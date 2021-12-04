/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:30:22 by fenedina          #+#    #+#             */
/*   Updated: 2021/12/04 17:55:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		min_max(int nb, int *point);
int		ft_putchar(int c, int *point);
int		ft_printf(const char *format, ...);
int		ft_print_arg(char c, va_list ap, int *point);
int		ft_putchar_p(unsigned long long c, int *point);
int		ft_hex(unsigned int i, char *base, int *point);
int		ft_hex_p(unsigned long long i, char *base, int *point);

void	ft_putstr(char *str, int *point);
void	ft_putnbr(int nb, int *point);
void	ft_unsig(unsigned int nb, int *point);
void	ft_point(unsigned long long p, int *point);

#endif
