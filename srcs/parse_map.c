/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:12:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 17:13:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		parse_command(t_pstate *state, char *str)
{
	if (ft_strcmp(str + 2, "start") == 0)
		state->start = true;
	if (ft_strcmp(str + 2, "end") == 0)
		state->end = true;
}

static int		parse_room(t_anthill *anthill, char *str, t_pstate *state)
{
	char		*name;

	if ((name = ft_strextract(str, ' ')) == NULL)
		return (-1);
	anthill_add_room(anthill, name);
	if (state->start)
	{
		anthill_set_start(anthill, name);
		state->start = false;
	}
	if (state->end)
	{
		anthill_set_end(anthill, name);
		state->end = false;
	}
	free(name);
	return (0);
}

static int		parse_pipe(t_anthill *anthill, char *str)
{
	char		*name;

	if ((name = ft_strextract(str, '-')) == NULL)
		return (-1);
	anthill_add_pipe(anthill, name, ft_strchr(str, '-') + 1);
	free(name);
	return (0);
}

int				parse_map(int fd, t_anthill *anthill, t_list *log)
{
	char		*str;
	t_pstate	state;

	state.start = false;
	state.end = false;
	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '#')
		{
			if (str[1] == '#')
				parse_command(&state, str);
		}
		else if (ft_strchr(str, '-') == NULL)
		{
			if (parse_room(anthill, str, &state) == -1)
				return (-1);
		}
		else
			parse_pipe(anthill, str);
		if (ft_list_push_back(log, str) == -1)
			return (-1);
	}
	return (0);
}
