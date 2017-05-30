#include <stdarg.h> 
#include <stdio.h>
#include "ft_printf.h"

void print_flags(t_flags flags)
{
		ft_putstr("\n");
	ft_putstr("hash:");
	ft_putnbr(flags.hash);
	ft_putstr("\n");
	ft_putstr("neg:");
	ft_putnbr(flags.neg);
	ft_putstr("\n");
	ft_putstr("plus:");
	ft_putnbr(flags.plus_sign);
	ft_putstr("\n");
	ft_putstr("space:");
	ft_putnbr(flags.space);
	ft_putstr("\n");
	ft_putstr("zero:");
	ft_putnbr(flags.zero_spacer);
	ft_putstr("\n");
	ft_putstr("precision:");
	ft_putnbr(flags.precision);
	ft_putstr("\n");
	ft_putstr("WIDTH");
	ft_putnbr(flags.width);
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("H:");
	ft_putnbr(flags.h);
	ft_putstr("\n");
	ft_putstr("HH:");
	ft_putnbr(flags.hh);
	ft_putstr("\n");
	ft_putstr("l:");
	ft_putnbr(flags.l);
	ft_putstr("\n");
	ft_putstr("ll:");
	ft_putnbr(flags.ll);
	ft_putstr("\n");
	ft_putstr("j:");
	ft_putnbr(flags.j);
	ft_putstr("\n");
	ft_putstr("z:");
	ft_putnbr(flags.z);
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
	ft_putstr("\n");
}

char	*ft_remalloc(char *str, size_t size)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	if (str)
	{
		p = (char *)malloc(sizeof(char) * (size));
		if (!p)
			return (NULL);
		ft_bzero(p, size);
		ft_strcpy(p, str);
		free(str);
		str = NULL;
	}
	return (p);
}

int		get_size(uintmax_t num, int base)
{
	int len;

	len = 1;
	while (num /= base)
		len++;
	return (len);
}

void	number_print(char *str, t_flags flags)
{
	int size;

	size = ft_strlen(str);
	if (flags.neg)
	{
		ft_putstr(str);
		prepend_width(flags, flags.width - size);
	}
	else
	{
		prepend_width(flags, flags.width - size);
		ft_putstr(str);
	}
}

void	num_to_s(uintmax_t number, t_flags flags, char before)
{
	int		len;
	char	*nbr;

	len = get_size(number, 10);
	if (flags.precision >= len && !(flags.zero_spacer = 0))
		len = flags.precision;
	if (before != 0 && !flags.zero_spacer)
		len++;
	else if (before == '-' && flags.zero_spacer && !flags.neg)
		len++;
	nbr = ft_strnew(len);
	nbr[len] = '\0';
	while (--len >= 0)
	{
		if (number != 0)
			nbr[len] = number % 10 + '0';
		else
			nbr[len] = '0';
		number /= 10;
	}
	if (before != 0 && flags.zero_spacer && flags.width  - 1)
		ft_putchar(before);
	else if (before != 0)
		nbr[0] = before;
	number_print(nbr, flags);
}

intmax_t promo_check(va_list ap, t_flags flags, char *fmt)
{

	intmax_t	res;
	if (*fmt == 'D' || flags.l)
		res = va_arg(ap, long);
	else if (flags.h)
		res = (short)va_arg(ap, int);
	else if (flags.hh)
		res = (signed char)va_arg(ap, int);
	else if (flags.ll)
		res = va_arg(ap, long long);
	else if (flags.z)
		res = va_arg(ap, ssize_t);
	else if (flags.j)
		res = va_arg(ap, intmax_t);
	else
		res = va_arg(ap, int);
	return (res);
}

void		num_parse(va_list ap, t_flags flags, char *fmt)
{
	intmax_t	number;
	char		before;

	number = promo_check(ap, flags, fmt);
	if (flags.plus_sign > 0)
		before = '+';
	else
		before = 0;
	if (flags.space && !flags.plus_sign)
		before = ' ';
	if (number < 0 && number * -1 > 0)
		before = '-';
	if (number == 0 && !flags.width && flags.precision)
		return ;
	if (number == 0 && flags.precision)
		ft_putchar(' ');
	num_to_s((uintmax_t)number, flags, before);
}

void check_spec(char *fmt, t_flags flags, va_list ap)
{
	if (*fmt == '%')
		ft_putchar('%');
	if (*fmt == 'c' || *fmt == 'C')
		chars(ap, flags, *fmt);
	if (*fmt == 's' || *fmt == 'S')
	 	str_parse(ap, flags, *fmt);
	if (*fmt == 'i' || *fmt == 'd' || *fmt == 'D')
		num_parse(ap, flags, fmt);
}

int setup(char *fmt, va_list ap)
{
	t_flags flags;
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
		{
			flags = init_flags(flags);
			if (*fmt == 0)
				return (1);
			flags = check_flags(fmt, flags, ap);
			while (*fmt && !ft_isalpha(*fmt) && *fmt != '%')
				fmt++;
			flags = check_mod(fmt, flags);
			while ((*fmt == 'l' || *fmt == 'h' || *fmt == 'z' || *fmt == 'j') && *fmt)
				fmt++;
			check_spec(fmt, flags, ap);
			print_flags(flags);
		}
		fmt++;
	}
	return (1);
}
int	 ft_printf(char *fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  setup(fmt, ap);
  va_end(ap);
  return (0);
}


int main()
{

  ft_printf("%-30.2s", "STring");
   return 0;
}