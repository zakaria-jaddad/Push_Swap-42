/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/26 02:26:29 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
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

int	*make_arr(char **elements)
{
	int	*arr;
	int	*arr_head;

	arr = (int *)malloc((count_elements(elements)) * sizeof(int));
	arr_head = arr;
	if (arr == NULL)
		return (NULL);
	while (*elements)
	{
		if (ft_atoi(*elements) == ATOIERROR || (ft_atoi(*elements) < INT_MIN
				|| ft_atoi(*elements) > INT_MAX))
			return (free((void *) arr), arr = NULL);
		*arr = (int) ft_atoi(*elements);
		(arr++, elements++);
	}
	return (arr_head);
}

int	*parse_elements(char *elements)
{
	char	**split_elements;
	int *arr;

	// split elements based on spaces
	split_elements = ft_split(elements, ' ');
	if (split_elements == NULL)
		return (NULL);
	(free(elements), elements = NULL);

	// check if all elements are digits
	if (is_all_digits(split_elements) == 0)
		return (free_args(split_elements), split_elements = NULL, NULL);

	// convert elements to a list of integers
	arr = make_arr(split_elements);
	printf("arrr %s\n", (char *) arr);
	if (arr == NULL)
		return (free_args(split_elements), split_elements = NULL, NULL);

	for (int i = 0; i < count_elements(split_elements); i++)
		printf("%d\n", arr[i]);

	return ((int *)split_elements);
}

/* t_stack *stack_a = create_stack(--argc, ++argv); */
int	main(int argc, char **argv)
{
	char	*elements;
	int		*arr;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error("Error\n");
	arr = parse_elements(elements);
	(void)arr;
	/* ft_printf("%s", elements); */
	/* free(elements); */
	return (EXIT_SUCCESS);
}
