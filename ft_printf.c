#include "print.h"
#include <stdarg.h>
#include <limits.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_hex(long long int i, char *base)
{
	if (i >= 16)
		ft_hex(i / 16, base);
	ft_putchar(base[i % 16]);
}

int	min_max(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb == INT_MAX)
	{
		write(1, "2", 1);
		nb = 147483647;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	char	b;

	nb = min_max(nb);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb < 10)
	{
		b = (char) nb + '0';
		write(1, &b, 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_unsig(long long int nb)
{
	char	b;

	if (nb < 0)
		nb = -nb;
	if (nb < 10)
	{
		b = (char) nb + '0';
		write(1, &b, 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_print_arg(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'x')
		ft_hex(va_arg(ap, long long int), "0123456789abcdef");
	else if (c == 'X')
		ft_hex(va_arg(ap, long long int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ft_unsig(va_arg(ap, long long int));
	else if (c == 'p')
		ft_point(va_arg(ap, unsigned long));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char	c;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_print_arg(*(++format), ap);
		else
			ft_putchar(*format);
		format++;
	}
	i++;
	if (format[i] == '%')
		ft_putchar('%');
	if (format[i] == 'c')
		ft_putchar(c);
	va_end(ap);
	return (1);
}

#include <stdio.h>

int	main()
{
	printf("%u\n", 76);
	ft_printf("%u\n", 76);
	ft_printf("hello mother fucka %c %% %d\n  %s %X", 'a', 11 / 5, "what?", 154);
	return (0);
}
