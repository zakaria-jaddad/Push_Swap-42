/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/12 21:10:46 by zajaddad         ###   ########.fr       */
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

void hardcoded_three_number_sort(t_stack **stack) 
{
        int top;
        int mid;
        int bottom;

        top = (*stack)->index;
        mid = (*stack)->next->index;
        bottom = (*stack)->next->next->index;
        if (is_stack_sorted(*stack) == 0 && top > mid && top > bottom)
                ra(stack);

        top = (*stack)->index;
        mid = (*stack)->next->index;
        bottom = (*stack)->next->next->index;
        if (is_stack_sorted(*stack) == 0 && (bottom < top || bottom < mid))
                rra(stack);

        top = (*stack)->index;
        mid = (*stack)->next->index;
        bottom = (*stack)->next->next->index;
        if (is_stack_sorted(*stack) == 0 && (bottom > top || bottom > mid))
                sa(stack);
}


int find_element_position(t_stack *stack, int element_index)
{
        int counter;
        
        counter = 0;
        while (stack)
        {
                if (stack->index == element_index) 
                        return (counter);
                counter++;
                stack = stack->next;
        }
        return (-1);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
        int     last_pivot_one;
        int     pivot_one;
        int     pivot_two;
        if (stacksize(*stack_a) == 3)
                hardcoded_three_number_sort(stack_a);
        last_pivot_one = -1;
        pivot_one = stacksize(*stack_a) / 3;
        pivot_two = stacksize(*stack_a) / 6;

        // part One
        while (stacksize(*stack_a) > 3)
        {
                if ((*stack_a)->index < pivot_one)
                {
                        pb(stack_b, stack_a);
                        //  if stack b has more than one element
                        if (stacksize(*stack_b) > 1)
                        {
                                // check the if  last_pivot_one <= top element index <= pivot_two 
                                if ((*stack_b)->index >= last_pivot_one && (*stack_b)->index <= pivot_two)
                                        rb(stack_b);
                        }
                        // if stack b size == pivot_one
                        if (stacksize(*stack_b) == pivot_one)
                        {
                                // update pivotes
                                last_pivot_one = pivot_one;
                                pivot_one += stacksize(*stack_a) / 3;
                                pivot_two = last_pivot_one + (stacksize(*stack_a) / 6);
                        }
                }
                else
                        ra(stack_a);
        }
        // stack a has 3 elements should be sorted
        hardcoded_three_number_sort(stack_a);

        // part Two
        int largest_number_index;
        int stack_a_bottom_index;

        stack_a_bottom_index = stacklast(*stack_a)->index;
        largest_number_index = stack_a_bottom_index;

        // since largest_number_index == stack_a_bottom_index pa and ra it is

        while (*stack_b)
        {
                while ((*stack_b) && (*stack_b)->index != (*stack_a)->index - 1) {
                        if (largest_number_index == stack_a_bottom_index || stack_a_bottom_index < (*stack_b)->index) 
                        {

                                // update stack a bottom index
                                /* printf("hello \n"); */

                                pa(stack_a, stack_b);
                                ra(stack_a);
                                stack_a_bottom_index = stacklast(*stack_a)->index;
                        }
                        else 
                        {
                                if (find_element_position(*stack_b, (*stack_a)->index - 1) > (stacksize(*stack_b) / 2))
                                        rrb(stack_b);
                                else
                                        rb(stack_b);
                        }
                }

                while ((*stack_b) && (*stack_b)->index == (*stack_a)->index - 1)
                        pa(stack_a, stack_b);

                if (stacklast(*stack_a)->index == (*stack_a)->index - 1)
                {
                        while ((*stack_a)->index - 1 == stacklast(*stack_a)->index) {
                                rra(stack_a);
                                stack_a_bottom_index = stacklast((*stack_a))->index;
                        }

                }
                if (is_stack_sorted(*stack_a) && stacksize(*stack_b)  == 0 && *stack_b == NULL)
                        break;
        }
}

int	main(int argc, char **argv)
{
	char	*elements;
	t_stack	*stack_a;
	t_stack	*stack_b;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error();
	stack_b = NULL;
	stack_a = parse_elements(elements);
	if (stack_a == NULL)
		prog_error();
        if (is_stack_sorted(stack_a) == 1)
                return (0);

        
        /* for (t_stack *head = stack_a; head  != NULL; head = head->next) */
        /*         printf("|number: %d, index: %d|\n", head->number, head->index); */

        // sort stack
        sort(&stack_a, &stack_b);
        /* printf("After Stack A\n"); */
        /* for (t_stack *head = stack_a; head  != NULL; head = head->next) */
        /*         printf("|number: %d, index: %d|\n", head->number, head->index); */
        /* printf("After Stack B\n"); */
        /* for (t_stack *head = stack_b; head  != NULL; head = head->next) */
        /*         printf("|number: %d, index: %d|\n", head->number, head->index); */

	stackclear(&stack_a);
	stackclear(&stack_b);
	stack_a = NULL;
	stack_b = NULL;
	return (EXIT_SUCCESS);
}
