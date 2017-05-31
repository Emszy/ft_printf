/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prepend_width(t_flags flags, int width)
{
	int		x;
	char	spaces;

	x = -1;
	if (flags.spaces == 1)
		spaces = ' ';
	else
		spaces = '0';
	while (++x < width)
		ft_putchar(spaces);
}

void	print_char(va_list ap, t_flags flags)
{
	char c;

	c = va_arg(ap, int);
	prepend_width(flags, flags.width);
	ft_putchar(c);
}

void	chars(va_list ap, t_flags flags, char specifier)
{
	if (specifier == 'c' && flags.l == 0)
		print_char(ap, flags);
	else
	{
		prepend_width(flags, flags.width);
		ft_putstr(wide_to_s(va_arg(ap, wint_t)));
	}
}
