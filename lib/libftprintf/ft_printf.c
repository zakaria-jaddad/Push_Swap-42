/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:36:41 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/28 14:53:39 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_format(char fmt, va_list ap, int *counter)
{
	if (fmt == 'c')
		*counter += ft_putchar(va_arg(ap, int));
	else if (fmt == 's')
		*counter += ft_putstr(va_arg(ap, char *));
	else if (fmt == 'p')
		ft_putaddress((size_t)va_arg(ap, void *), counter);
	else if (fmt == 'd' || fmt == 'i')
		ft_putnbr(va_arg(ap, int), counter);
	else if (fmt == 'u')
		ft_put_unsigned_nbr(va_arg(ap, unsigned int), counter);
	else if (fmt == 'x')
		ft_puthex(va_arg(ap, unsigned int), "0123456789abcdef", counter);
	else if (fmt == 'X')
		ft_puthex(va_arg(ap, unsigned int), "0123456789ABCDEF", counter);
	else
		*counter += ft_putchar(fmt);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	ap;

	counter = 0;
	if (write(1, NULL, 0) == -1)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			counter += ft_putchar(*format++);
			continue ;
		}
		print_format(*++format, ap, &counter);
		if (*format++ == 0)
			break ;
	}
	va_end(ap);
	return (counter);
}
