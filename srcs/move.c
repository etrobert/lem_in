/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:04:45 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 12:52:53 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		move_print(int fd, char *str)
{
	static bool	start = true;

	if (str == NULL)
	{
		ft_dprintf('\n');
		start = true;
	}
	else
	{
		if (!start)
			ft_dprintf(" %s", str);
		else
			ft_dprintf("%s", str);
		start = false;
	}
}

static bool		ant_steps(int fd, t_anthill *anthill, t_path *path, int cur_ant)
{
	t_list_it	it;
	t_room		*room;
	bool		moved;

	ft_dprintf(2, "\nDEBUG %s\n", ((t_room *)(ft_list_front(path->path)))->name);
	moved = false;
	it = ft_list_begin(path->path);
	while (!ft_list_it_end(path->path, it))
	{
		room = (t_room *)(ft_list_it_get(path->path, it));
		// ATTENTION ESPACE PRINT
		if (cur_ant != EMPTY_ROOM)
		{
			ft_dprintf(fd, "L%d-%s ", cur_ant, room->name);
			moved = true;
		}
		ft_swap_int(&cur_ant, &(room->ant));
		ft_list_it_inc(&it);
	}
	if (cur_ant != EMPTY_ROOM)
		ft_dprintf(fd, "L%d-%s ", cur_ant, anthill->end->name);
	return (moved);
}

static bool		move_turn(int fd, t_anthill *anthill, t_list *paths, int *new_ant)
{
	t_list_it	it;
	t_path		*path;
	bool		moved;

	moved = false;
	it = ft_list_begin(paths);
	while (!ft_list_it_end(paths, it))
	{
		path = (t_path *)(ft_list_it_get(paths, it));
		// Handle NULL path
		if (path->ants_to_go > 0)
		{
//			ft_dprintf(2, "DEBUG %s %d\n", ((t_room *)(ft_list_front(path->path)))->name, *new_ant);
			moved = moved || ant_steps(fd, anthill, path, (*new_ant)++);
			--path->ants_to_go;
		}
		else
			moved = moved || ant_steps(fd, anthill, path, EMPTY_ROOM);
		ft_list_it_inc(&it);
	}
	ft_dprintf(fd, "\n");
	return (moved);
}

void			move(int fd, t_anthill *anthill, t_list *paths)
{
	int			new_ant;

	new_ant = 1;
	while (move_turn(fd, anthill, paths, &new_ant))
	{
	}
}
