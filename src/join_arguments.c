/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:37:04 by zajaddad          #+#    #+#             */
/*   Updated: 2025/01/26 00:20:09 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}


int	isempty_argument(char *argument)
{
	if (argument == NULL)
		return (0);
	while (*argument)
	{
		if (ft_isspace(*argument++) == 0)
			return (0);
	}
	return (1);
}

static char	**join_with_space(int argc, char **args)
{
	char	**space_args;
	char	**space_args_head;

	if (args == NULL)
		return (NULL);
	space_args = (char **)malloc((argc + 1) * sizeof(char *));
	if (space_args == NULL)
		return (NULL);
	space_args_head = space_args;
	while (*args)
	{
		if (isempty_argument(*args) == 1)
			return (free_args(space_args_head), NULL);
		*space_args = ft_strjoin(*args++, " ");
		if (*space_args++ == NULL)
			return (free_args(space_args_head));
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
			return (free(joined_args), free_args(space_args));
		free(joined_args);
		joined_args = NULL;
		joined_args = joined_args_placeholder;
		joined_args_placeholder = NULL;
	}
	free_args(space_args);
	return (joined_args);
}
