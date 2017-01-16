/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 17:09:08 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_anthill	*anthill;
	t_list		*log;
	int			n;

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
	if ((n = solve(anthill, log)) != 0)
		print_error(n);
	ft_list_apply(log, &free);
	ft_list_delete(log);
	anthill_delete(anthill);
	return (0);
}
