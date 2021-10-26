/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:44:29 by fenedina          #+#    #+#             */
/*   Updated: 2021/10/26 19:32:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsig(long long int nb, int *point)
{
	char	b;

	if (nb < 0)
		nb = -nb;
	if (nb < 10)
	{
		b = (char) nb + '0';
		ft_putchar(b, point);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, point);
		ft_putnbr(nb % 10, point);
	}
}

void	ft_point(long long int p, int *point)
{
	ft_putchar('0', point);
	ft_putchar('x', point);
	ft_hex(p, "0123456789abcdef", point);
}

int	ft_print_arg(char c, va_list ap, int *point)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), point);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), point);
	else if (c == 'x')
		ft_hex(va_arg(ap, long long int), "0123456789abcdef", point);
	else if (c == 'X')
		ft_hex(va_arg(ap, long long int), "0123456789ABCDEF", point);
	else if (c == '%')
		ft_putchar('%', point);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), point);
	else if (c == 'u')
		ft_unsig(va_arg(ap, long long int), point);
	else if (c == 'p')
		ft_point(va_arg(ap, long long int), point);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;
	int		*point;

	res = 0;
	point = &res;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_print_arg(*(++format), ap, point);
		else
			ft_putchar(*format, point);
		format++;
	}
	va_end(ap);
	return (res);
}
