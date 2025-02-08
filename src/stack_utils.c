/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:29:54 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/08 20:31:47 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL)
		return ;
	last = stacklast(*stack);
	if (last == NULL)
		*stack = new;
	else
		last->next = new;
}

t_stack	*stack_new(int number, unsigned int index)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->number = number;
	node->index = index;
	return (node);
}

void	stackdelone(t_stack *stack)
{
	if (stack != NULL)
        {
		free(stack);
                stack = NULL;
        }
}

void	stackclear(t_stack **stack)
{
	t_stack	*stack_node;
	t_stack	*p;

	if (stack == NULL)
		return ;
	stack_node = *stack;
	p = *stack;
	while (p)
	{
		p = p->next;
		stackdelone(stack_node);
		stack_node = p;
	}
	*stack = NULL;
}
