/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/15 21:22:30 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list_it		shortest_path(t_list *paths);

void			putstr_fd_line(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int 			main(void)
{
	t_anthill	*anthill;
	t_list 		*result;
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
	result = paths_list(anthill);
	plan_movement(anthill, result);
	//Sil ny a pas de chemin possible on fait error
	ft_list_apply(result, (t_f_apply)&print_path);
	ft_printf("\n");
	ft_list_apply(result, (t_f_apply)(&path_delete));
	ft_list_delete(result);


	ft_list_apply(log, (t_f_apply)(&putstr_fd_line));
	ft_list_apply(log, &free);
	ft_list_delete(log);

	ft_printf("\n");
	printf("////////////////////////\n");
//	ft_printf("\nAnd the winner is ...\n");
//	print_path(ft_list_it_get(result, shortest_path(result)));
//	ft_list_apply(select_paths(result), (t_f_apply)(&print_path));
	
	anthill_delete(anthill);
	return (0);
}
