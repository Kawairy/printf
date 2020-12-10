/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvin <delvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:32:13 by delvin            #+#    #+#             */
/*   Updated: 2020/12/10 20:55:28 by delvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("%-20.2%");
}

	/*while (*form)
		{
			if (*form == '%')
				{
					if (*form++ == 'c')
						{
							c = (char) va_arg(arg, int);
							write(1, &c, 1);
						}
					if (*form++ == 's')
						{
							s = va_arg(arg, char *);
							while (*s)
            	    	    	write(1, s++, 1);
						}
					//if (*form++ == d)
				}
			else
					write(1, form, 1);
			form++;
		}*/
