#include "ft_printf.h"
t_flags init_flags(t_flags flags)
{
	flags.hash = 0;
	flags.neg = 0;
	flags.plus_sign = 0;
	flags.space = 0;
	flags.zero_spacer = 0;
	flags.modula = 0;
	flags.precision = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.j = 0;
	flags.z = 0;
	return (flags);
}

t_flags		check_wid(char *fmt, t_flags flags, va_list ap)
{
	flags.width = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '*')
	{
		flags.width = va_arg(ap, int);
		fmt++;
	}
	if (flags.precision < 0)
		flags.precision = 0;

	return (flags);
}

t_flags		check_precis(char *fmt, t_flags flags, va_list ap)
{
	fmt++;
	flags.precision = ft_atoi(fmt);
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '*')
	{
		flags.precision = va_arg(ap, int);
		fmt++;
	}
	return (flags);
}

t_flags		check_flags(char *fmt, t_flags flags, va_list ap)
{
	flags.width = 0;
	while (*fmt && !ft_isalpha(*fmt) && *fmt != '%')
	{
		if (*fmt == '-')
			flags.neg = 1;
		else if (*fmt == '+')
			flags.plus_sign = 1;
		else if (*fmt == ' ')
			flags.zero_spacer = 1;
		else if (*fmt == '#')
			flags.hash = 1;
		else if (*fmt == '0')
			flags.zero_spacer = 1;
		else if ((ft_isdigit(*fmt) || *fmt == '*') && flags.width == 0)
			flags = check_wid(fmt, flags, ap);
		if (*fmt == '.')
			flags = check_precis(fmt, flags, ap);
			fmt++;
	}
	return (flags);
}

t_flags	check_mod(char *fmt, t_flags flags)
{
	if (*fmt == 'h' && *fmt + 1 && *fmt + 1 != 'h')
		flags.h = 1;
	else if (*fmt == 'h' && *fmt + 1 && *fmt + 1 == 'h')
		flags.hh = 1;
	else if (*fmt == 'l' && *fmt + 1 && *fmt + 1 != 'l')
		flags.l = 1;
	else if (*fmt == 'l' && *fmt + 1 && *fmt + 1 == 'l')
		flags.ll = 1;
	else if (*fmt == 'j')
		flags.j = 1;
	else if (*fmt == 'z')
		flags.z = 1;
	return (flags);
}
