/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:14:42 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/25 20:15:06 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack(int argc, char **argv)
{
  (void) argc;
  (void) argv;
	return (t_stack *)malloc(sizeof(t_stack));
}
