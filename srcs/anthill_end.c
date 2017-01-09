/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:55:03 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 16:14:20 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool			anthill_end(t_anthill *anthill, t_room *room)
{
	if (anthill == NULL)
		return (true);
	return (anthill->end == room);
}
