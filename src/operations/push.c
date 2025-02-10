/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:43:59 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/10 14:38:45 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **stack_to, t_stack **stack_in)
{
	t_stack	*last_in;
	t_stack	*last_to;

	last_in = stacklast(*stack_in);
	last_to = stacklast(*stack_to);
	if (last_in->prev != NULL)
		last_in->prev->next = NULL;
	else
		*stack_in = NULL;
	last_in->prev = last_to;
	if (last_in->prev != NULL)
		last_in->prev->next = last_in;
	else
		*stack_to = last_in;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
