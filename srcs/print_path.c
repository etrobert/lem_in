/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:28:44 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 12:37:18 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_path(t_path *path)
{
	t_list_it	it;

	if (path == NULL)
		return ;
	it = ft_list_begin(path->path);
	ft_printf("Chemin ; ants_to_go : %d\n", path->ants_to_go);
	while (!ft_list_it_end(path->path, it))
	{
		ft_printf("Etape : %s\n",
				((t_room *)ft_list_it_get(path->path, it))->name);
		ft_list_it_inc(&it);
	}
}
