/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:08:50 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/08 20:31:50 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_elements(char **split_elements)
{
	int	counter;

	counter = 0;
	while (split_elements[counter])
		counter++;
	return (counter);
}

static int	*make_arr(char **elements, int *arr_size)
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
		*arr = (int)ft_atoi(*elements);
		(arr++, elements++, (*arr_size)++);
	}
	return (arr_head);
}

static int	check_duplication(int *arr, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	if (arr == NULL)
		return (0);
	while (i < arr_size - 1)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (arr[i] == arr[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

t_stack	*parse_elements(char *elements)
{
	char	**split_elements;
	int		*arr;
	int		arr_size;
        t_stack         *stack;

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
	if (arr == NULL || arr_size == 0)
		return (free_args(split_elements), split_elements = NULL, NULL);
	(void)(free_args(split_elements), split_elements = NULL);

	// check duplication in the list
	if (check_duplication(arr, arr_size) == 1)
		return (free(arr), arr = NULL, NULL);

        // arr has no duplicate and not empty
        // create stack
        stack = create_stack(arr, arr_size);
	return (free(arr), arr = NULL, stack);
}
