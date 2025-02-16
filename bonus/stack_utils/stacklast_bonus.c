/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:58:49 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/13 16:32:48 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

t_stack	*stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
