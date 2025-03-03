/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:43:59 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:36 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **stack_to, t_stack **stack_in)
{
	t_stack	*tmp;
	t_stack	*first_in;
	t_stack	*first_to;

	first_in = *stack_in;
	first_to = *stack_to;
	tmp = first_in->next;
	first_in->next = first_to;
	if (first_to != NULL)
		first_to->prev = first_in;
	if (tmp != NULL)
		tmp->prev = NULL;
	*stack_to = first_in;
	*stack_in = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
