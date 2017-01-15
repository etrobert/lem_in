/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 20:30:24 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_it		shortest_path(t_list *paths);

int 			main(void)
{
	t_anthill	*anthill;
	t_list 		*result;
	/*
	t_list		*log;

	if ((log = ft_list_new()) == NULL)
	{
		ft_dprintf(2, "ERROR: [main] Couldnt create log list\n");
		return (-1);
	}
	*/
	anthill = parse(0);
	/*
	anthill = anthill_new();

	anthill_add_room(anthill, "00");
	anthill_add_room(anthill, "01");
	anthill_add_room(anthill, "02");
	anthill_add_room(anthill, "03");
	anthill_add_room(anthill, "04");
	anthill_add_room(anthill, "05");
	anthill_add_room(anthill, "06");
	anthill_add_room(anthill, "07");

	anthill_set_start(anthill, "01");
	anthill_set_end(anthill, "00");

	anthill_add_pipe(anthill, "00", "04");
	anthill_add_pipe(anthill, "00", "06");
	anthill_add_pipe(anthill, "01", "03");
	anthill_add_pipe(anthill, "04", "03");
	anthill_add_pipe(anthill, "05", "02");
	anthill_add_pipe(anthill, "03", "05");
	anthill_add_pipe(anthill, "04", "02");
	anthill_add_pipe(anthill, "02", "01");
	anthill_add_pipe(anthill, "07", "06");
	anthill_add_pipe(anthill, "07", "02");
	anthill_add_pipe(anthill, "07", "04");
	anthill_add_pipe(anthill, "06", "05");
	*/

	anthill_print(2, anthill);

	if (anthill->start == NULL || anthill->end == NULL)
	{
		//FREE
		ft_dprintf(2, "ERROR: No start or end room\n");
		return (0);
	}
	//Si start et end sont la meme map on fait rien
	//Sils sont voisins on les decale tous dun coup
	//Sinon
	result = paths_list(anthill);
	//Sil ny a pas de chemin possible on fait error
	ft_list_apply(result, (t_f_apply)&print_path);

	printf("////////////////////////\n");
//	ft_printf("\nAnd the winner is ...\n");
//	print_path(ft_list_it_get(result, shortest_path(result)));
//	ft_list_apply(select_paths(result), (t_f_apply)(&print_path));
	
	// FREE
	return (0);
}
