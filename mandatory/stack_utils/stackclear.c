/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:01:21 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/09 15:01:30 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
