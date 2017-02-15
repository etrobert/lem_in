/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:40:07 by etrobert          #+#    #+#             */
/*   Updated: 2017/02/15 19:18:31 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		solve_normal(t_anthill *anthill, t_list *log)
{
	t_list		*all_paths;
	t_list		*selected_paths;

	all_paths = paths_list(anthill);
	if (ft_list_size(all_paths) == 0)
	{
		ft_list_delete(all_paths);
		return (LEM_ERR_NO_PATH);
	}
	selected_paths = select_paths(all_paths);
	plan_movement(anthill, selected_paths);
	ft_list_apply(log, (t_f_apply)(&ft_putstr_line));
	ft_printf("\n");
	move(anthill, selected_paths);
	ft_list_apply(all_paths, (t_f_apply)(&path_delete));
	ft_list_delete(all_paths);
	ft_list_delete(selected_paths);
	return (0);
}

static int		solve_voisins(t_anthill *anthill, t_list *log)
{
	int			i;
	bool		start;

	ft_list_apply(log, (t_f_apply)(&ft_putstr_line));
	ft_printf("\n");
	start = true;
	i = 1;
	while (i <= anthill->ants)
	{
		move_print(i, anthill->end, &start);
		++i;
	}
	ft_printf("\n");
	return (0);
}

int				solve(t_anthill *anthill, t_list *log)
{
	t_list		*nei;

	if (anthill->start == NULL || anthill->end == NULL)
	{
		return (LEM_ERR_NO_START_END);
	}
	if ((nei = anthill_neighbors(anthill, anthill->start)) == NULL)
		return (LEM_ERR_MALLOC);
	if (anthill->start == anthill->end)
	{
		ft_list_apply(log, (t_f_apply)(&ft_putstr_line));
		ft_printf("\n\n");
		return (0);
	}
	else if (ft_list_find(nei, anthill->end) != ft_list_end(nei))
	{
		ft_list_delete(nei);
		return (solve_voisins(anthill, log));
	}
	ft_list_delete(nei);
	return (solve_normal(anthill, log));
}
