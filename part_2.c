/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:44:12 by fenedina          #+#    #+#             */
/*   Updated: 2021/10/26 19:41:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int *point)
{
	write(1, &c, 1);
	*point += 1;
	return (*point);
}

void	ft_putstr(char *str, int *point)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		ft_putchar('0', point);
	while (str[i])
	{
		ft_putchar(str[i], point);
		i++;
	}
}

int	ft_hex(long long int i, char *base, int *point)
{
	if (i >= 16)
		ft_hex(i / 16, base, point);
	ft_putchar(base[i % 16], point);
	return (0);
}

int	min_max(int nb, int *point)
{
	if (nb == INT_MIN)
	{
		ft_putchar('-', point);
		ft_putchar('2', point);
		nb = 147483648;
	}
	if (nb == INT_MAX)
	{
		ft_putchar('2', point);
		nb = 147483647;
	}
	return (nb);
}

void	ft_putnbr(int nb, int *point)
{
	char	b;

	nb = min_max(nb, point);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', point);
	}
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
