/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:58:36 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/10 21:46:39 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	last = stacklast(*stack);
	first = *stack;
	last->next = first;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
		return ;
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
		return ;
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_a == NULL || *stack_a == NULL) || (stack_b == NULL
			|| *stack_b == NULL))
		return ;
	if (stacksize(*stack_a) == 1 || stacksize(*stack_b) == 1)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
