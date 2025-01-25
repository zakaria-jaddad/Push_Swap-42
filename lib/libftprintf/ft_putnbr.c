/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:50:39 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/16 21:54:58 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr(int n, int *counter)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		*counter += ft_putchar('-');
		long_n *= -1;
	}
	if (long_n >= 0 && long_n < 10)
		*counter += ft_putchar((long_n + '0'));
	else
	{
		ft_putnbr((long_n / 10), counter);
		*counter += ft_putchar(((long_n % 10) + '0'));
	}
}
