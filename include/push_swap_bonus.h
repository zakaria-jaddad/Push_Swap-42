/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:14 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/25 20:32:34 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/libftprintf/ft_printf.h"

typedef struct s_stack
{
	unsigned int	index;
	int				number;
	struct s_stack	*next;
}					t_stack;

#endif // !PUSH_SWAP_H
