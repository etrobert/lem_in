/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:20:36 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 20:08:43 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		paths_list_end(t_list *cur_path, t_list *paths)
{
	t_path		*path;

	if ((path = path_new(cur_path)) == NULL)
		return (-1);
	if (ft_list_push_back(paths, path) == -1)
	{
		path_delete(path);
		return (-1);
	}
	return (0);
}

static int		paths_list_r(t_anthill *anthill,
		t_list *cur_path, t_list *paths)
{
	t_room		*node;
	t_list		*neighbors;
	t_list_it	it;

	node = ft_list_back(cur_path);
	if (node->marked)
		return (0);
	if (anthill_end(anthill, node))
		return (paths_list_end(cur_path, paths));
	anthill_mark(anthill, node);
	if ((neighbors = anthill_neighbors(anthill, node)) == NULL)
		return (-1);
	it = ft_list_begin(neighbors);
	while (!ft_list_it_end(neighbors, it))
	{
		if (ft_list_push_back(cur_path, ft_list_it_get(neighbors, it)) == -1)
			return (-1);
		if (paths_list_r(anthill, cur_path, paths) == -1)
			return (-1);
		ft_list_it_inc(&it);
		ft_list_pop_back(cur_path);
	}
	ft_list_delete(neighbors);
	anthill_unmark(anthill, node);
	return (0);
}

t_list			*paths_list(t_anthill *anthill)
{
	t_list		*cur_path;
	t_list		*paths;

	if ((cur_path = ft_list_new()) == NULL)
		return (NULL);
	if ((paths = ft_list_new()) == NULL)
	{
		ft_list_delete(cur_path);
		return (NULL);
	}
	if (ft_list_push_back(cur_path, anthill_start(anthill)) == -1 ||
			paths_list_r(anthill, cur_path, paths) == -1)
	{
		ft_list_delete(cur_path);
		ft_list_delete(paths);
		return (NULL);
	}
	ft_list_apply(paths, (t_f_apply)(&path_remove_ext));
	ft_list_delete(cur_path);
	return (paths);
}
