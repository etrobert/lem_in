/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:42:00 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:16:11 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*

static void		anthill_add_pipe_rooms(t_anthill *anthill,
		char *room1, char *room2, t_pipe *pipe)
{
	t_list_it	it;
	t_room		*room;

	it = ft_list_begin(anthill->rooms);
	while (!ft_list_it_end(anthill->rooms, it))
	{
		room = (t_room *)ft_list_it_get(anthill->rooms, it);
		if (ft_strcmp(room1, room->name) == 0)
			pipe->room1 = room;
		if (ft_strcmp(room2, room->name) == 0)
			pipe->room2 = room;
		ft_list_it_inc(&it);
	}
}

int				anthill_add_pipe(t_anthill *anthill, char *room1, char *room2)
{
	t_pipe		*pipe;

	if (anthill == NULL)
		return (-1);
	if ((pipe = (t_pipe *)malloc(sizeof(t_pipe))) == NULL)
		return (-1);
	pipe->room1 = NULL;
	pipe->room2 = NULL;
	anthill_add_pipe_rooms(anthill, room1, room2, pipe);
	if (pipe->room1 == NULL || pipe->room2 == NULL ||
			ft_list_push_back(anthill->pipes, pipe) == -1)
	{
		free(pipe);
		return (-1);
	}
	return (0);
}
*/

int				anthill_add_pipe(t_anthill *anthill, char *room1, char *room2)
{
	t_room		*r1;
	t_room		*r2;
	t_list_it	it;
	t_room		*room;

	r1 = NULL;
	r2 = NULL;
	it = anthill->rooms->begin(anthill->rooms);
	while (!anthill->rooms->it_end(anthill->rooms, it))
	{
		room = (t_room *)(anthill->rooms->it_get(anthill->rooms, it));
		if (ft_strcmp(room->name, room1) == 0)
			r1 = room;
		if (ft_strcmp(room->name, room2) == 0)
			r2 = room;
		ft_list_it_inc(&it);
	}
	if (r1 == NULL || r2 == NULL ||
			r1->neighbors->push_back(r1->neighbors, r2) ||
			r2->neighbors->push_back(r2->neighbors, r1))
		return (-1);
	return (0);
}
