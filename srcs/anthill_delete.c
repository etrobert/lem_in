/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:08:27 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 18:09:19 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	anthill_delete(t_anthill *anthill)
{
	if (anthill == NULL)
		return ;
	ft_list_delete(anthill->rooms);
	ft_list_delete(anthill->pipes);
	free(anthill);
}
