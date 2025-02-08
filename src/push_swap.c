/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/07 19:16:36 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <cstdio>
#include <stdio.h>

/*
 * TODO:
 * [] Parse user input
 * [] sort numbers
 * [] Print operations
 */

int	is_digit(char *element)
{
	int	digit;
	int	sign;

	digit = 0;
	sign = 0;
	while (*element)
	{
		if (*element == '-' || *element == '+')
		{
			if ((digit == 0 && sign == 0) && *(element + 1) != 0)
			{
				(element++, digit++, sign++);
				continue ;
			}
			else
				return (0);
		}
		if (!ft_isdigit(*element))
			return (0);
		(element++, digit++);
	}
	return (1);
}
/*
 * is_all_digits: checks if all elements are valid
 * means all elements are valid digits
 */
static int	is_all_digits(char **elements)
{
	while (*elements)
	{
		if (is_digit(*elements) == 0)
			return (0);
		elements++;
	}
	return (1);
}

int	count_elements(char **split_elements)
{
	int	counter;

	counter = 0;
	while (split_elements[counter])
		counter++;
	return (counter);
}

int	*make_arr(char **elements, unsigned int *arr_size)
{
	int	*arr;
	int	*arr_head;

	arr = (int *)malloc((count_elements(elements)) * sizeof(int));
	arr_head = arr;
	if (arr == NULL)
		return (NULL);
	*arr_size = 0;
	while (*elements)
	{
		if (ft_atoi(*elements) == ATOIERROR || (ft_atoi(*elements) < INT_MIN
				|| ft_atoi(*elements) > INT_MAX))
			return (free(arr_head), *arr_size = 0, arr = NULL);
		*arr = (int) ft_atoi(*elements);
		(arr++, elements++, (*arr_size)++);
	}
	return (arr_head);
}

/*
 * check_duplication: 
 * duplicate number found 	-> 1
 * duplicate number not found 	-> 0
 */
int	check_duplication(int *arr, unsigned int arr_size) 
{
	/* int i; */
	/* int j; */
	/* i = 0; */
	(void) arr;
	return (0);
}

t_stack *parse_elements(char *elements)
{
	char	**split_elements;
	int *arr;
	unsigned int arr_size;

	// split elements based on spaces
	split_elements = ft_split(elements, ' ');
	if (split_elements == NULL)
		return (NULL);
	(free(elements), elements = NULL);

	// check if all elements are digits
	if (is_all_digits(split_elements) == 0)
		return (free_args(split_elements), split_elements = NULL, NULL);

	// convert elements to a list of integers
	arr = make_arr(split_elements, &arr_size);
	if (arr == NULL)
		return (free_args(split_elements), split_elements = NULL, NULL);
	(void) (free_args(split_elements), split_elements = NULL);

	// check duplication in the list
	if (check_duplication(arr, arr_size) == 1)
		return (free(arr), arr = NULL, NULL);
	
	return ((t_stack *)arr);
}


/* t_stack *stack_a = create_stack(--argc, ++argv); */
int	main(int argc, char **argv)
{
	char	*elements;
	int		*arr;
	unsigned int	arr_size;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error("Error\n");
	arr = parse_elements(elements);
	if (arr == NULL)
		prog_error("Error\n");

	// check duplication
	/* if (check_duplication(arr) == 1) */
	/* ft_printf("%s", elements); */
	/* free(elements); */
	return (EXIT_SUCCESS);
}
