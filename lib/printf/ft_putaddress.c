/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:11:46 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/16 23:13:42 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putaddress(size_t address, int *counter)
{
	*counter += ft_putstr("0x");
	ft_puthex(address, "0123456789abcdef", counter);
}
