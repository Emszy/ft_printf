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

void x_mod(t_flags flags, char *fmt, char *new)
{
	int size;

	size = 0;
 	if (flags.hash && !flags.zero_spacer)
	{
		new[1] = 'x';
		new[0] = '0';
	}
	if (*fmt == 'X')
	{
		while (new[size])
		{
			new[size] = ft_toupper(new[size]);
			size++;
		}
	}
	if (flags.hash && flags.zero_spacer)
	{
		if (*fmt == 'x')
			ft_putstr("0x");
		else if (*fmt == 'X')
			ft_putstr("0X");
		flags.width -= 2;
	}
	number_print(new, flags);
}


void	x_to_s(uintmax_t n, t_flags flags, char *fmt, int size)
{
	char	*new;

	size = get_size(n, 16);
	if (n == 0)
		flags.hash = 0;
	if (flags.precision > size)
		size = flags.precision;
	if (flags.hash && !flags.zero_spacer)
		size += 2;
	new = ft_strnew(size);
	new[size] = '\0';
	while (--size >= 0)
	{
		if (n != 0)
		{
			if ((n % 16) > 9)
				new[size] = (n % 16) - 10 + 'a';
			else
				new[size] = (n % 16) + '0';
		}
		else
			new[size] = '0';
		n /= 16;
	}
	x_mod(flags, fmt, new);
}

uintmax_t promoting_x(va_list ap, t_flags flags)
{
	uintmax_t	res;

	if (flags.hh)
		res = (unsigned char)va_arg(ap, int);
	else if (flags.h)
		res = (unsigned short)va_arg(ap, int);
	else if (flags.l)
		res = va_arg(ap, unsigned long);
	else if (flags.ll)
		res = va_arg(ap, unsigned long long);
	else if (flags.j)
		res = va_arg(ap, uintmax_t);
	else if (flags.z)
		res = va_arg(ap, ssize_t);
	else
		res = va_arg(ap, unsigned int);
	return (res);
}


void		xnum_parse(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	res = promoting_x(ap, flags);

	if (res == 0 && !flags.width && flags.precision)
		return ;
	if (res == 0 && flags.precision)
	{
		prepend_width(flags, flags.width);
		ft_putchar(' ');
		return ;
	}
	x_to_s(res, flags, fmt, 0);
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
	if (*fmt == 'u' || *fmt == 'U')
		unum_parse(ap, flags, fmt);
	if (*fmt == 'x' || *fmt == 'X')
		xnum_parse(ap, flags, fmt);
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
			//print_flags(flags);
		}
		else
			ft_putchar(*fmt);
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
  ft_printf("%x intbetween %s aksd", 13476, "thisnext");
   return 0;
}