/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:30:51 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 11:58:02 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list_it	shortest_path(t_list *paths)
{
	t_list_it		it;
	t_list_it		best;
	size_t			best_size;
	t_path			*path;

	best_size = SIZE_MAX;
	best = ft_list_begin(paths);
	it = ft_list_begin(paths);
	while (!ft_list_it_end(paths, it))
	{
		path = (t_path *)(ft_list_it_get(paths, it));
		if (ft_list_size(path->path) < best_size)
		{
			best = it;
			best_size = ft_list_size(path->path);
		}
		ft_list_it_inc(&it);
	}
	return (best);
}

static void			clean_paths(t_list *paths, t_path *best)
{
	t_list_it		cur_path;
	t_list_it		cur_room;
	t_path			*path;
	t_room			*room;
	bool			erased;

	cur_path = ft_list_begin(paths);
	while (!ft_list_it_end(paths, cur_path))
	{
		path = (t_path *)(ft_list_it_get(paths, cur_path));
		erased = false;
		cur_room = ft_list_begin(best->path);
		while (!erased && !ft_list_it_end(best->path, cur_room))
		{
			room = (t_room *)(ft_list_it_get(best->path, cur_room));
			if (!ft_list_it_end(path->path, ft_list_find(path->path, room)))
			{
				cur_path = ft_list_erase(paths, cur_path);
				erased = true;
			}
			ft_list_it_inc(&cur_room);
		}
		if (!erased)
			ft_list_it_inc(&cur_path);
	}
}

t_list				*select_paths(const t_list *paths)
{
	t_list_it		it;
	t_list			*best_paths;
	t_list			*paths_cpy;

	if ((paths_cpy = ft_list_cpy(paths)) == NULL)
		return (NULL);
	if ((best_paths = ft_list_new()) == NULL)
	{
		free(paths_cpy);
		return (NULL);
	}
	while (!ft_list_empty(paths_cpy))
	{
		it = shortest_path(paths_cpy);
		ft_list_push_back(best_paths, ft_list_it_get(paths_cpy, it));
		clean_paths(paths_cpy, (t_path *)(ft_list_it_get(paths_cpy, it)));
	}
	ft_list_delete(paths_cpy);
	return (best_paths);
}
