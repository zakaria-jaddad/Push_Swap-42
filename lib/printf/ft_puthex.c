/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:37:46 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/17 17:14:23 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthex(size_t n, const char *base, int *counter)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_puthex((n / base_len), base, counter);
	*counter += ft_putchar(base[n % base_len]);
}
