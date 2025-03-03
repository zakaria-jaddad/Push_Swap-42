/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:12:34 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/14 18:31:40 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*old_first;
	t_stack	*new_first;

	old_first = *stack;
	new_first = old_first->next;
	last = stacklast(*stack);
	old_first->next = NULL;
	old_first->prev = last;
	last->next = old_first;
	new_first->prev = NULL;
	*stack = new_first;
}

void	ra(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
		return ;
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
		return ;
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_a == NULL || *stack_a == NULL) || (stack_b == NULL
			|| *stack_b == NULL))
		return ;
	if (stacksize(*stack_a) == 1 || stacksize(*stack_b) == 1)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
