/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:14:42 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/13 16:35:51 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*make_sorted_arr(int *arr, int arr_size)
{
	int	*sorted_arr;
	int	i;
	int	j;

	if (arr == NULL || arr_size == 0)
		return (NULL);
	sorted_arr = malloc(sizeof(int) * arr_size);
	if (sorted_arr == NULL)
		return (NULL);
	i = -1;
	while (++i < arr_size)
		sorted_arr[i] = arr[i];
	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size - i - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
				ft_swap(&sorted_arr[j], &sorted_arr[j + 1]);
			j++;
		}
		i++;
	}
	return (sorted_arr);
}

static int	index_number(int *sorted_arr, int number, int arr_size)
{
	int	min;
	int	max;
	int	mid;

	if (sorted_arr == NULL)
		return (-1);
	min = 0;
	max = arr_size - 1;
	while (min <= max)
	{
		mid = (int)((min + max) / 2);
		if (sorted_arr[mid] > number)
			max = mid - 1;
		else if (sorted_arr[mid] < number)
			min = mid + 1;
		else
			return (mid);
	}
	return (-1);
}

t_stack	*create_stack(int *arr, int arr_size)
{
	t_stack	*stack_head;
	t_stack	*stack_node;
	int		*sorted_arr;
	int		i;

	if (arr == NULL || arr_size == 0)
		return (NULL);
	i = 0;
	stack_head = NULL;
	sorted_arr = make_sorted_arr(arr, arr_size);
	if (sorted_arr == NULL)
		return (NULL);
	while (i < arr_size)
	{
		stack_node = stacknew(arr[i], index_number(sorted_arr, arr[i],
					arr_size));
		if (stack_node == NULL)
			return (stackclear(&stack_head), stack_head = NULL,
				free(sorted_arr), sorted_arr = NULL, NULL);
		stackadd_back(&stack_head, stack_node);
		i++;
	}
	return (free(sorted_arr), sorted_arr = NULL, stack_head);
}
