#include "ft_printf.h"

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