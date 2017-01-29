/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:35:25 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:18:09 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			anthill_add_room(t_anthill *anthill, char *name)
{
	t_room	*room;

	if (anthill == NULL)
		return (0);
	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (-1);
	if (ft_list_push_back(anthill->rooms, room) == -1)
	{
		free(room);
		return (-1);
	}
	if ((room->neighbors = ft_list_new()) == NULL)
	{
		free(room);
		return (-1);
	}
	if ((room->name = ft_strdup(name)) == NULL)
	{
		free(room);
		return (-1);
	}
	room->marked = false;
	room->ant = EMPTY_ROOM;
	return (0);
}
