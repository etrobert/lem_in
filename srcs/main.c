/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 12:30:28 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_it		shortest_path(t_list *paths);

void			putstr_line(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int 			main(void)
{
	t_anthill	*anthill;
	t_list 		*all_paths;
	t_list		*selected_paths;
	t_list		*log;

	if ((log = ft_list_new()) == NULL)
	{
		ft_dprintf(2, "ERROR: [main] Couldnt create log list\n");
		return (-1);
	}
	if ((anthill = parse(0, log)) == NULL)
	{
		ft_dprintf(2, "ERROR: [main] Couldnt achieve parsing\n");
		return (-1);
	}

//	anthill_print(2, anthill);

	if (anthill->start == NULL || anthill->end == NULL)
	{
		anthill_delete(anthill);
		ft_list_apply(log, &free);
		ft_list_delete(log);
		ft_dprintf(2, "ERROR: No start or end room\n");
		return (0);
	}
	//Si start et end sont la meme map on fait rien
	//Sils sont voisins on les decale tous dun coup
	//Sinon
	all_paths = paths_list(anthill);

	//Sil ny a pas de chemin possible on fait error
	
	selected_paths = select_paths(all_paths);

	plan_movement(anthill, selected_paths);
	ft_list_apply(selected_paths, (t_f_apply)&print_path);
	ft_printf("\n");

	// Affichage des logs
	ft_list_apply(log, (t_f_apply)(&putstr_line));
	ft_list_apply(log, &free);
	ft_list_delete(log);

	ft_printf("\n");

	move(1, anthill, selected_paths);

	//Liberation de la memoire
	ft_list_apply(all_paths, (t_f_apply)(&path_delete));
	ft_list_delete(all_paths);
	ft_list_delete(selected_paths);

	anthill_delete(anthill);
	return (0);
}
