/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 01:41:26 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/12 02:29:51 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned int n, char *hex_base)
{
	int		count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, hex_base);
	count += ft_putchar(hex_base[n % 16]);
	return (count);
}

static int	ft_putpointer(unsigned long n)
{
	int		count;

	count = 0;
	if (n > 15)
		count += ft_putpointer(n / 16);
	count += ft_putchar(HEXLOWER[n % 16]);
	return (count);
}

int	print_hex(va_list args, char *hex_base)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_puthex(n, hex_base));
}

int	print_pointer(va_list args)
{
	unsigned long	n;

	n = va_arg(args, unsigned long);
	if (n == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_putpointer(n));
}
