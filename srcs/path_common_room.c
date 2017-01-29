/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_common_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:39 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 18:49:33 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool			path_common_room(t_list *l1, t_list *l2)
{
	t_list_it	it;

	it = l1->begin(l1);
	while (!l1->it_end(l1, it))
	{
		if (!l2->it_end(l2, l2->find(l2, l1->it_get(l1, it))))
			return (true);
		ft_list_it_inc(&it);
	}
	return (false);
}
