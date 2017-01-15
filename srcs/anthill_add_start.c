/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:39:28 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/10 18:43:46 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			anthill_add_start(t_anthill *anthill, char *name)
{
	if (anthill == NULL)
		return (0);
	if (anthill_add_room(anthill, name) == -1)
		return (-1);
	anthill->start = (t_room *)ft_list_back(anthill->rooms);
	return (0);
}
