/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:12:23 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 20:30:07 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		parse_ants(int fd, t_anthill *anthill)
{
	char		*str;

	if (get_next_line(fd, &str) <= 0)
		return (-1);
	anthill->ants = ft_atoi(str);
	free(str);
	return (0);
}

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

static int		parse_map(int fd, t_anthill *anthill)
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
		free(str);
	}
	return (0);
}

t_anthill		*parse(int fd)
{
	t_anthill	*anthill;

	if ((anthill = anthill_new()) == NULL)
		return (NULL);
	parse_ants(fd, anthill);
	parse_map(fd, anthill);
	return (anthill);
}
