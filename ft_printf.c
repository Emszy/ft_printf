#include <stdarg.h> 
#include <stdio.h>
#include "ft_printf.h"

void print_flags(t_flags flags)
{
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

void check_spec(char * fmt, t_flags flags, va_list ap)
{

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
			check_spec(*fmt, flags, ap);
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
	char c = 'i';
  ft_printf("     %#-+0327.32hs %-21.32lld %-3c", "sdskjdfb", 8231, c);
   return 0;
}