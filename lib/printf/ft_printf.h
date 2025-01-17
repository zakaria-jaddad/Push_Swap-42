/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:42:56 by zajaddad          #+#    #+#             */
/*   Updated: 2024/11/28 15:12:25 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_putnbr(int n, int *counter);
void	ft_put_unsigned_nbr(unsigned int n, int *counter);
void	ft_puthex(size_t n, const char *base, int *counter);
void	ft_putaddress(size_t address, int *counter);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);

#endif
