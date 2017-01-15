/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:54:24 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 19:57:27 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*path_new(t_list *path)
{
	t_path	*ret;

	if ((ret = (t_path *)(malloc(sizeof(t_path)))) == NULL)
		return (NULL);
	if ((ret->path = ft_list_cpy(path)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->ants_to_go = 0;
	return (ret);
}
