/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:28:44 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 18:41:23 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_path(t_list *path)
{
	t_list_it	it;

	if (path == NULL)
		return ;
	it = ft_list_begin(path);
	ft_printf("VOila un bien beau chemin\n");
	while (!ft_list_it_end(path, it))
	{
		ft_printf("Etape : %s\n", ((t_room *)ft_list_it_get(it))->name);
		ft_list_it_inc(&it);
	}
}

