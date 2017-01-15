/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:54:05 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/14 21:03:03 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		ft_dprintf(fd, "\n");
		ft_list_it_inc(&it);
	}
}

static void		anthill_print_pipes(int fd, t_list *pipes)
{
	t_list_it	it;
	t_pipe		*pipe;

	ft_dprintf(fd, "Pipes list :\n");
	it = ft_list_begin(pipes);
	while (!ft_list_it_end(pipes, it))
	{
		pipe = (t_pipe *)ft_list_it_get(pipes, it);
		ft_dprintf(fd, "%s -- %s\n", pipe->room1->name, pipe->room2->name);
		ft_list_it_inc(&it);
	}
}

void			anthill_print(int fd, t_anthill *anthill)
{
	if (anthill == NULL)
		return ;
	ft_dprintf(fd, "Anthill with %d ants :\n", anthill->ants);
	anthill_print_rooms(fd, anthill);
	anthill_print_pipes(fd, anthill->pipes);
}
