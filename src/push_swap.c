/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/09 15:47:42 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

/*
 * TODO:
 * [X] Parse user input
 * [] Create stack operations
 * [] sort numbers
 * [] Print operations
 */

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error();
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();

        for (t_stack *head = stack_a; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }
        printf("\n");


        for (t_stack *head = stacklast(stack_a); head != NULL; head = head->prev) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }
        printf("\n");


        stack_a = NULL;
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
