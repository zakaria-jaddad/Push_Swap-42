/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:32:29 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/08 15:06:27 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_digit_string(char *element)
{
	int	digit;
	int	sign;

	digit = 0;
	sign = 0;
	while (*element)
	{
		if (*element == '-' || *element == '+')
		{
			if ((digit == 0 && sign == 0) && *(element + 1) != 0)
			{
				(element++, digit++, sign++);
				continue ;
			}
			else
				return (0);
		}
		if (!ft_isdigit(*element))
			return (0);
		(element++, digit++);
	}
	return (1);
}

int	is_all_digits(char **elements)
{
	while (*elements)
	{
		if (is_digit_string(*elements) == 0)
			return (0);
		elements++;
	}
	return (1);
}

