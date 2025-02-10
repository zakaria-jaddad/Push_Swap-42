/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:23:31 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/10 20:21:53 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
        second = first->next;
        first->next = second->next;
        if (second->next != NULL)
                second->next->prev = first;
        second->prev = NULL;
        second->next = first;
        *stack = second;

}

void	sa(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
		return ;
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	if (stacksize(*stack) == 1)
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
