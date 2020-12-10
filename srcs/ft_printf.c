/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvin <delvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:36:47 by delvin            #+#    #+#             */
/*   Updated: 2020/12/10 20:53:10 by delvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, form);
	count += ft_parse_all(form, arg);
	va_end(arg);
	return (count);
}

int	main(void)
{
	ft_printf("%s", "ghtbn");
}
