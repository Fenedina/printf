/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:29:59 by fenedina          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:04 by fenedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_p(unsigned long long c, int *point)
{
	write(1, &c, 1);
	*point += 1;
	return (*point);
}

int	ft_hex_p(unsigned long long i, char *base, int *point)
{
	if (i >= 16)
		ft_hex_p(i / 16, base, point);
	ft_putchar_p(base[i % 16], point);
	return (0);
}

void	ft_point(unsigned long long p, int *point)
{
	ft_putchar('0', point);
	ft_putchar('x', point);
	ft_hex_p(p, "0123456789abcdef", point);
}
