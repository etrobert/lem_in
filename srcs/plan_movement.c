/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 18:27:50 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 19:31:31 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*best_path(t_list *paths)
{
	t_path		*best;
	t_path		*path;
	t_list_it	it;

	best = (t_path *)ft_list_front(paths);
	it = ft_list_begin(paths);
	while (!ft_list_it_end(paths, it))
	{
		path = (t_path *)ft_list_it_get(paths, it);
		if (ft_list_size(path->path) + path->ants_to_go <
				ft_list_size(best->path) + best->ants_to_go)
			best = path;
		ft_list_it_inc(&it);
	}
	return (best);
}

void			plan_movement(t_anthill *anthill, t_list *paths)
{
	int			ants;

	ants = anthill->ants;
	while (ants > 0)
	{
		++best_path(paths)->ants_to_go;
		--ants;
	}
}
