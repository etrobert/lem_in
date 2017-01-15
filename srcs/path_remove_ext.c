/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_remove_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:07:42 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 20:09:10 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	path_remove_ext(t_path *path)
{
	if (path == NULL)
		return ;
	ft_list_pop_front(path->path);
	ft_list_pop_back(path->path);
}
