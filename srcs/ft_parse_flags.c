/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvin <delvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 21:17:27 by delvin            #+#    #+#             */
/*   Updated: 2020/12/10 21:20:15 by delvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_flag_width(va_list arg, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(arg, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_flag_dot(const char *form, int start,
			t_flags *flags, va_list arg)
{
	int i;

	i = start;
	i++;
	if (form[i] == '*')
	{
		flags->dot = va_arg(arg, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(form[i]))
			flags->dot = (flags->dot * 10) + (form[i++] - '0');
	}
	return (i);
}

int			ft_flag_parse(const char *form, int i, t_flags *flags, va_list arg)
{
	while (form)
	{
		if (!ft_isdigit(form) && !ft_is_types(form)
		&& !ft_is_flags(form))
			break ;
		if (form == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (form == '.')
			i = ft_flag_dot(form, i, flags, arg);
		if (form == '-')
			*flags = ft_flag_minus(*flags);
		if (form == '*')
			*flags = ft_flag_width(arg, *flags);
		if (ft_isdigit(form))
			*flags = ft_flag_digit(form, *flags);
		if (ft_is_types(form))
		{
			flags->type = form;
			break ;
		}
		i++;
	}
	return (i);
}