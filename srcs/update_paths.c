/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 19:26:04 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/29 20:13:35 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clear_paths(t_list *paths, t_list *new_path, t_list_it it)
{
	t_path		*cur_path;

	while (!paths->it_end(paths, it))
	{
		cur_path = (t_path *)(paths->it_get(paths, it));
		if (path_common_room(cur_path->path, new_path))
			it = paths->erase(paths, it);
		else
			ft_list_it_inc(&it);
	}
}

static int		add_to_paths(t_list *paths, t_list *new_path, t_list_it it)
{
	t_path		*path;

	if ((path = path_new(new_path)) == NULL)
		return (-1);
	if (ft_list_insert(paths, it, path) == -1)
	{
		path_delete(path);
		return (-1);
	}
	return (0);
}

int				update_paths(t_list *paths, t_list *new_path)
{
	t_list_it	it;
	t_path		*cur_path;

	if (paths == NULL)
		return (0);
	it = paths->begin(paths);
	while (!paths->it_end(paths, it))
	{
		cur_path = (t_path *)(paths->it_get(paths, it));
		if (new_path->size(new_path) >= cur_path->path->size(cur_path->path))
		{
			clear_paths(paths, new_path, it);
			return (add_to_paths(paths, new_path, it));
		}
		else if (path_common_room(cur_path->path, new_path))
			return (0);
		ft_list_it_inc(&it);
	}
	return (add_to_paths(paths, new_path, it));
}
