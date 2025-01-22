/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:10 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/22 15:46:10 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * TODO:
 * [] Parse user input
 * [] sort numbers
 * [] Print operations
 */


int	main(int argc, char **argv)
{
	char	*elements;

	elements = join_arguments(--argc, ++argv);
	printf("%s", elements);
	free(elements);
	/* t_stack *stack_a = create_stack(--argc, ++argv); */
	return (EXIT_SUCCESS);
}
