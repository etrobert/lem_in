/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:04:45 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 16:47:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static bool		ant_steps(t_anthill *anthill, t_path *path,
		int cur_ant, bool *line_start)
{
	t_list_it	it;
	t_room		*room;
	bool		moved;

	moved = false;
	it = ft_list_begin(path->path);
	while (!ft_list_it_end(path->path, it))
	{
		room = (t_room *)(ft_list_it_get(path->path, it));
		if (cur_ant != EMPTY_ROOM)
		{
			move_print(cur_ant, room, line_start);
			moved = true;
		}
		ft_swap_int(&cur_ant, &(room->ant));
		ft_list_it_inc(&it);
	}
	if (cur_ant != EMPTY_ROOM)
		move_print(cur_ant, anthill->end, line_start);
	return (moved);
}

static bool		move_turn(t_anthill *anthill, t_list *paths, int *new_ant)
{
	t_list_it	it;
	t_path		*path;
	bool		moved;
	bool		line_start;

	line_start = true;
	moved = false;
	it = ft_list_begin(paths);
	while (!ft_list_it_end(paths, it))
	{
		if ((path = (t_path *)(ft_list_it_get(paths, it))) != NULL)
		{
			if (path->ants_to_go > 0)
			{
				moved = ant_steps(anthill, path, (*new_ant)++, &line_start) ||
					moved;
				--path->ants_to_go;
			}
			else
				moved = ant_steps(anthill, path, EMPTY_ROOM, &line_start) ||
					moved;
			ft_list_it_inc(&it);
		}
	}
	return (moved);
}

void			move(t_anthill *anthill, t_list *paths)
{
	int			new_ant;

	new_ant = 1;
	while (move_turn(anthill, paths, &new_ant))
	{
		ft_printf("\n");
	}
	ft_printf("\n");
}
