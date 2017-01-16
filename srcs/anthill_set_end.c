/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_set_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:22:30 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 12:37:34 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			anthill_set_end(t_anthill *anthill, char *name)
{
	t_list_it	it;
	t_room		*room;

	it = ft_list_begin(anthill->rooms);
	while (!ft_list_it_end(anthill->rooms, it))
	{
		room = (t_room *)ft_list_it_get(anthill->rooms, it);
		if (ft_strcmp(room->name, name) == 0)
			anthill->end = room;
		ft_list_it_inc(&it);
	}
}
