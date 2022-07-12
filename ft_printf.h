/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:45:13 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/12 14:44:27 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEXLOWER	"0123456789abcdef"
# define HEXUPPER	"0123456789ABCDEF"

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(va_list args);
int		print_int(va_list args);
int		print_uint(va_list args);
int		print_hex(va_list args, char *hex_base);
int		print_pointer(va_list args);
size_t	ft_strlen(const char *s);

#endif
