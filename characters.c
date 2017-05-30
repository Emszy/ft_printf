#include "ft_printf.h"


void prepend_width(t_flags flags, int width)
{
	int x;
	char spaces;

	x = -1;
	if(flags.zero_spacer == 1)
		spaces = '0';
	else
		spaces = ' ';
	while (++x < width)
		ft_putchar(spaces);
}

void print_char(va_list ap, t_flags flags)
{
	char c;

	c = va_arg(ap, int);
	prepend_width(flags, flags.width);
	ft_putchar(c);
}

void	putwide(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar((chr >> 6) + 0xC0);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar((chr >> 12) + 0xE0);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar((chr >> 18) + 0xF0);
		ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar((chr & 0x3F) + 0x80);
	}
}

void chars(va_list ap, t_flags flags, char specifier)
{
	if (specifier == 'c' && flags.l == 0)
		print_char(ap, flags);
	else
	{
		prepend_width(flags, flags.width);
		putwide(va_arg(ap, wint_t));
	}
}