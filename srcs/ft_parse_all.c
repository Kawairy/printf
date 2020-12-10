/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvin <delvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:10:39 by delvin            #+#    #+#             */
/*   Updated: 2020/12/10 21:21:00 by delvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

t_flags		ft_flags_base(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_is_types(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int			ft_is_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int			ft_parse_all(const char *form, va_list arg)
{
	int			i;
	t_flags		flags;
	int			count;

	i = 0;
	count = 0;
	while (form)
	{
		flags = ft_flags_base();
		if (!form[i])
			break ;
		else if (form[i] == '%' && form[i++] != 0)
		{
			i = ft_flag_parse(form, ++i, &flags, arg);
			if (ft_is_types(form))
				count += ft_treatment((char)flags.type, flags, arg);
			else if (form)
				count += ft_putchar(form);
		}
		else if (form != '%')
			count += ft_putchar(form);
		i++;
	}
	return (count);
}
