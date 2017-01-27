/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:12:23 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/18 17:14:42 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		parse_ants(int fd, t_anthill *anthill, t_list *log)
{
	char		*str;

	if (get_next_line(fd, &str) <= 0)
		return (-1);
	anthill->ants = ft_atoi(str);
	if (anthill->ants < 0)
	{
		free(str);
		return (-1);
	}
	if (ft_list_push_back(log, str) == -1)
		return (-1);
	return (0);
}

t_anthill		*parse(int fd, t_list *log)
{
	t_anthill	*anthill;

	if ((anthill = anthill_new()) == NULL)
		return (NULL);
	if (parse_ants(fd, anthill, log) == -1 ||
			parse_map(fd, anthill, log) == -1)
	{
		anthill_delete(anthill);
		return (NULL);
	}
	return (anthill);
}
