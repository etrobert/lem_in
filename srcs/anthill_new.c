/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:59:28 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 18:10:03 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_anthill		*anthill_new(void)
{
	t_anthill	*anthill;

	if ((anthill = (t_anthill *)malloc(sizeof(t_anthill))) == NULL)
		return (NULL);
	if ((anthill->rooms = ft_list_new()) == NULL)
	{
		anthill_delete(anthill);
		return (NULL);
	}
	if ((anthill->pipes = ft_list_new()) == NULL)
	{
		anthill_delete(anthill);
		return (NULL);
	}
	return (anthill);
}
