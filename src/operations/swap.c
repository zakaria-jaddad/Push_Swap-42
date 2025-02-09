/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:31 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/09 17:49:24 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*last;

	last = stacklast(*stack);
	last->next = *stack;
	last->next->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	sa(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) <= 1)
		return ;
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) <= 1)
		return ;
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((stack_a == NULL || *stack_a == NULL) || (stack_b == NULL
			|| *stack_b == NULL))
		return ;
	if (stacksize(*stack_a) == 1 || stacksize(*stack_a) == 1)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
