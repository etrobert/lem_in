/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_neighbors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:01:50 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:15:25 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
t_list			*anthill_neighbors(t_anthill *anthill, t_room *room)
{
	t_list_it	it;
	t_list		*list;
	t_pipe		*pipe;

	if (anthill == NULL || (list = ft_list_new()) == NULL)
		return (NULL);
	it = ft_list_begin(anthill->pipes);
	while (!ft_list_it_end(anthill->pipes, it))
	{
		pipe = (t_pipe *)ft_list_it_get(anthill->pipes, it);
		if (pipe->room1 == room)
			if (ft_list_push_back(list, pipe->room2) == -1)
			{
				ft_list_delete(list);
				return (NULL);
			}
		if (pipe->room2 == room)
			if (ft_list_push_back(list, pipe->room1) == -1)
			{
				ft_list_delete(list);
				return (NULL);
			}
		ft_list_it_inc(&it);
	}
	return (list);
}
*/

t_list			*anthill_neighbors(t_anthill *anthill, t_room *room)
{
	(void)anthill;
	return (room->neighbors);
}
