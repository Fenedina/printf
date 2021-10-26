/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:00:39 by fenedina          #+#    #+#             */
/*   Updated: 2021/10/26 19:07:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(int c, int *point);
void	ft_putstr(char *str, int *point);
int		ft_hex(long long int i, char *base, int *point);
int		min_max(int nb, int *point);
void	ft_putnbr(int nb, int *point);
void	ft_unsig(long long int nb, int *point);
void	ft_point(long long int p, int *point);
int		ft_print_arg(char c, va_list ap, int *point);
int		ft_printf(const char *format, ...);

#endif
