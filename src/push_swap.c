/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/09 18:38:54 by zajaddad         ###   ########.fr       */
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
        t_stack *stack_b;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error();
        stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();

        printf("Before\n");
        for (t_stack *head = stack_a; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }
        printf("\n");

        pa(&stack_a, &stack_b);
        pa(&stack_a, &stack_b);

        printf("After Stack A\n");
        for (t_stack *head = stack_a; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }
        printf("\n");
        printf("Stack B\n");
        for (t_stack *head = stack_b; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }

        printf("\n");
        pb(&stack_b, &stack_a);
        pb(&stack_b, &stack_a);
        pb(&stack_b, &stack_a);
        pb(&stack_b, &stack_a);
        for (t_stack *head = stack_a; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }
        printf("\n");
        for (t_stack *head = stack_b; head != NULL; head = head->next) {
                printf("|number: %d index : %d| --> ", head->number, head->index);
        }

        stack_a = NULL;
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
