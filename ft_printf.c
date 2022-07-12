/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:44:05 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/12 01:46:50 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

int	ft_putstr(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

static int	print_format(va_list args, const char c)
{
	int	len;

	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(args);
	else if (c == 'p')
		len = print_pointer(args);
	else if (c == 'd' || c == 'i')
		len = print_int(args);
	else if (c == 'u')
		len = print_uint(args);
	else if (c == 'x')
		len = print_hex(args, HEXLOWER);
	else if (c == 'X')
		len = print_hex(args, HEXUPPER);
	else if (c == '%')
		len = ft_putchar(c);
	return (len);
}

__attribute__((__format__ (__printf__, 1, 2)))
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s != '%')
			len += write(1, s, 1);
		else
		{
			s++;
			len += print_format(args, *s);
		}
		s++;
	}
	va_end(args);
	return (len);
}
