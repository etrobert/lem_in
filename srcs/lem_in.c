/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:23:09 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/27 19:29:38 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				lem_in(int fd)
{
	t_anthill	*anthill;
	t_list		*log;
	int			n;

	if ((log = ft_list_new()) == NULL)
	{
		print_error(LEM_ERR_MALLOC);
		return (-1);
	}
	if ((anthill = parse(fd, log)) == NULL)
	{
		print_error(LEM_ERR_PARSING);
		ft_list_apply(log, &free);
		ft_list_delete(log);
		return (-1);
	}
	if ((n = solve(anthill, log)) != 0)
		print_error(n);
	ft_list_apply(log, &free);
	ft_list_delete(log);
	anthill_delete(anthill);
	return (0);
}
