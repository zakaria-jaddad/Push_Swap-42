/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:07 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/26 01:10:44 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/libftprintf/ft_printf.h"

#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	unsigned int	index;
	int				number;
	struct s_stack	*next;
}					t_stack;

t_stack				*create_stack(int argc, char **args);
char				*join_arguments(int argc, char **args);
void				*free_args(char **args);
void				prog_error(char *err);
#endif // !PUSH_SWAP_H
