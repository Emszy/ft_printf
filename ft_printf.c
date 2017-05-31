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

void		p_to_s(void *pointer, t_flags flags)
{
	long	n;
	int		len;
	char	*new;

	n = (long)pointer;
	if (n == 0 && flags.precision)
	{
		number_print("0x", flags);
		return ;
	}
	len = get_size(n, 16) + 2;
	if (flags.precision > len - 2)
		len = flags.precision + 2;
	new = ft_strnew(len);
	new[len] = '\0';
	while (--len >= 0)
	{
		if (n != 0)
		{
			if ((n % 16) > 9)
				new[len] = (n % 16) - 10 + 'a';
			else
				new[len] = (n % 16) + '0';
		}
		else
			new[len] = '0';
		n /= 16;
	}
	new[1] = 'x';
	new[0] = '0';
	number_print(new, flags);
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
	if (*fmt == 'o' || *fmt == 'O')
		onum_parse(ap, flags, fmt);
	if (*fmt == 'p')
		p_to_s(va_arg(ap, void *), flags);
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
	void *p;
	p = "this";
  ft_printf("%p intbetween %s aksd\n", p, "ç");
  printf("%p intbetween %s aksd\n", p, "ç");
   return 0;
}