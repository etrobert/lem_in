/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:01:54 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 20:02:49 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	path_delete(t_path *path)
{
	if (path == NULL)
		return ;
	ft_list_delete(path->path);
	free(path);
}
