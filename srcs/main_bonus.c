/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:57:59 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/18 16:40:37 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int			i;
	int			fd;

	if (argc == 1)
		return (lem_in(0));
	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			print_error(LEM_ERR_OPEN);
		else
		{
			lem_in(fd);
			close(fd);
		}
		++i;
		if (i != argc)
			ft_printf("----------------------------------------------------\n");
	}
	return (0);
}
