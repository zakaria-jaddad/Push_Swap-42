/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:14 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/13 16:33:32 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

int	is_stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		while (tmp)
		{
			if (stack->index > tmp->index)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}
