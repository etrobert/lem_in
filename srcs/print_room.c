/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:31:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 16:32:34 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room(t_room *room)
{
	if (room == NULL)
		return ;
	ft_printf("Room \"%s\" marked :%d ant:%d\n",
			room->name, room->marked, room->ant);
}
