/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_unmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:21:32 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 16:22:21 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			anthill_unmark(t_anthill *anthill, t_room *room)
{
	(void)anthill;
	if (room == NULL)
		return ;
	room->marked = false;
}
