/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 18:35:55 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 			main(void)
{
	t_anthill	*anthill;
	t_room		r1, r2, r3;
	t_pipe		p;
	t_list 		*result;
	t_list_it	it;

	anthill = anthill_new();
	p = (t_pipe){&r1, &r2};
	r1 = (t_room){ft_strdup("PIECE 01"), false};
	r2 = (t_room){ft_strdup("PIECE 02"), false};
	r3 = (t_room){ft_strdup("PIECE 03"), false};
	ft_list_push_back(anthill->rooms, &r1);
	ft_list_push_back(anthill->rooms, &r2);
	ft_list_push_back(anthill->rooms, &r2);
	ft_list_push_back(anthill->pipes, &p);

	anthill->start = &r1;
	anthill->end = &r3;
	result = paths_list(anthill);
	
	it = ft_list_begin(result);
	while (!ft_list_it_end(result, it))
	{
		print_path((t_list *)ft_list_it_get(it));
		ft_list_it_inc(&it);
	}
	return (0);
}
