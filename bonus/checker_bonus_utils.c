/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:46:17 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/23 18:24:36 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	sort_stack_sort_stack(t_stack **stack_a, t_stack **stack_b,
		char *content)
{
	if (ft_strcmp(content, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(content, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(content, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(content, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(content, "pb\n") == 0)
		pa(stack_b, stack_a);
	else if (ft_strcmp(content, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(content, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(content, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(content, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(content, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(content, "rrr\n") == 0)
		rrr(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_list *operations)
{
	while (operations != NULL)
	{
		sort_stack_sort_stack(stack_a, stack_b, (char *)operations->content);
		operations = operations->next;
	}
}
