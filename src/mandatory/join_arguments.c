/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:37:04 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/18 00:39:28 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	*free_args(char ***args)
{
	int	i;

	i = 0;
	if (args == NULL || *args)
		return (NULL);
	while (*args[i])
		free(*args[i++]);
	free(*args);
        free(args);
	return (NULL);
}

static char	**join_with_space(int argc, char **args)
{
	char	**space_args;
	char	**space_args_head;

	if (args == NULL)
		return (NULL);
	space_args = (char **)malloc(argc * sizeof(char *));
	if (space_args == NULL)
		return (NULL);
	space_args_head = space_args;
	while (*args)
	{
		*space_args = ft_strjoin(*args++, " ");
		if (*space_args++ == NULL)
			return (free_args(&space_args_head));
	}
	*space_args = NULL;
	return (space_args_head);
}

char	*join_arguments(int argc, char **args)
{
	char	**space_args;
	char	*joined_args;
	char	*joined_args_placeholder;
	int		i;

	i = 0;
	joined_args = NULL;
        if (argc == 0 || *args == NULL)
                return (NULL);
	space_args = join_with_space(argc, args);
	if (space_args == NULL)
		return (NULL);
	while (space_args[i])
	{
		joined_args_placeholder = ft_strjoin(joined_args, space_args[i++]);
		if (joined_args_placeholder == NULL)
			return (free(joined_args), free_args(&space_args));
		free(joined_args);
                joined_args = NULL;
		joined_args = joined_args_placeholder;
		joined_args_placeholder = NULL;

	}
	free_args(&space_args);
	return (joined_args);
}

