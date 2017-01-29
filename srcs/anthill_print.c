/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:54:05 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:25:03 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		anthill_print_neighbors(int fd, t_room *room)
{
	t_list_it	it;
	t_room		*neighbor;

	ft_dprintf(fd, "Nei: ");
	it = room->neighbors->begin(room->neighbors);
	while (!ft_list_it_end(room->neighbors, it))
	{
		neighbor = (t_room *)(ft_list_it_get(room->neighbors, it));
		ft_dprintf(fd, "%s ", neighbor->name);
		ft_list_it_inc(&it);
	}
}

static void		anthill_print_rooms(int fd, t_anthill *anthill)
{
	t_list_it	it;
	t_room		*room;

	ft_dprintf(fd, "Rooms list :\n");
	it = ft_list_begin(anthill->rooms);
	while (!ft_list_it_end(anthill->rooms, it))
	{
		room = ((t_room *)ft_list_it_get(anthill->rooms, it));
		ft_dprintf(fd, "%s", room->name);
		if (room == anthill->start)
			ft_dprintf(fd, " START", room->name);
		if (room == anthill->end)
			ft_dprintf(fd, " END", room->name);
		anthill_print_neighbors(fd, room);
		ft_dprintf(fd, "\n");
		ft_list_it_inc(&it);
	}
}

void			anthill_print(int fd, t_anthill *anthill)
{
	if (anthill == NULL)
		return ;
	ft_dprintf(fd, "Anthill with %d ants :\n", anthill->ants);
	anthill_print_rooms(fd, anthill);
}
