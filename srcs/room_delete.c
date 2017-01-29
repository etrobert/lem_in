/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:23:22 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:20:15 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_delete(t_room *room)
{
	if (room == NULL)
		return ;
	ft_list_delete(room->neighbors);
	free(room->name);
	free(room);
}
