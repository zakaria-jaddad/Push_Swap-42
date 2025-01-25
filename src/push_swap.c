/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/25 20:18:34 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * TODO:
 * [] Parse user input
 * [] sort numbers
 * [] Print operations
 */


static void prog_error(char *err)
{
	ft_printf("%s", err);
	exit(EXIT_FAILURE);
}


int	main(int argc, char **argv)
{
	char	*elements;

	elements = join_arguments(--argc, ++argv);
	if (elements == NULL)
		prog_error("Error\n");
	ft_printf("%s", elements);
	free(elements);
	/* t_stack *stack_a = create_stack(--argc, ++argv); */
	return (EXIT_SUCCESS);
}
