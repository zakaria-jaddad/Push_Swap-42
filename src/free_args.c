/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:17:11 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/26 00:17:40 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*free_args(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (NULL);
	while (args[i])
		free(args[i++]);
	free(args);
	return (NULL);
}
