/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_width(char **fmt, t_flags flags, va_list ap)
{
	flags.width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		*fmt += 1;
	if (**fmt == '*')
	{
		flags.width = va_arg(ap, int);
		*fmt += 1;
	}
	if (flags.width < 0)
	{
		flags.neg = 1;
		flags.width *= -1;
	}
}

static void	set_precision(char **fmt, t_flags flags, va_list ap)
{
	*fmt += 1;
	flags.precision = 1;
	flags.precision = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		*fmt += 1;
	if (**fmt == '*')
	{
		flags.precision = va_arg(ap, int);
		*fmt += 1;
	}
	if (flags.precision < 0)
		flags.precision = 0;
}

void		check_flags(char *fmt, t_flags flags, va_list ap)
{
	while (*fmt && !ft_isalpha(*fmt) && *fmt != '%')
	{
		if (*fmt == '-')
			flags.neg = 1;
		else if (*fmt == '+')
			flags.plus_sign = 1;
		else if (*fmt == ' ')
			flags.space = 1;
		else if (*fmt == '#')
			flags.hash = 1;
		else if (*fmt == '0')
			flags.zero_spacer = 1;
		else if (ft_isdigit(*fmt) || *fmt == '*')
			set_width(&fmt, flags, ap);
		if (*fmt == '.')
			set_precision(&fmt, flags, ap);
		if (*fmt && !ft_isalpha(*fmt))
			fmt++;
	}
}


t_flags		check_mod(char *fmt, t_flags flags)
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
