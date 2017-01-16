/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:46:57 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 16:47:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		move_print(int ant, t_room *room, bool *start)
{
	if (!(*start))
		ft_printf(" ");
	ft_printf("L%d-%s", ant, room->name);
	*start = false;
}
