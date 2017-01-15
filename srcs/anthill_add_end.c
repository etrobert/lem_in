/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_add_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:41:34 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/10 18:48:57 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			anthill_add_end(t_anthill *anthill, char *name)
{
	if (anthill == NULL)
		return (0);
	if (anthill_add_room(anthill, name) == -1)
		return (-1);
	anthill->end = (t_room *)ft_list_back(anthill->rooms);
	return (0);
}
