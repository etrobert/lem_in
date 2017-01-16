/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:04:35 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/16 17:09:59 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_error(int n)
{
	ft_dprintf(2, "ERROR");
	if (LEM_ERROR_V_ON)
	{
		ft_dprintf(2, ": ");
		if (n == LEM_ERR_NO_PATH)
			ft_dprintf(2, "There is no path from start to end.");
		else if (n == LEM_ERR_NO_START_END)
			ft_dprintf(2, "There is no start or end");
		else if (n == LEM_ERR_MALLOC)
			ft_dprintf(2, "A malloc failed");
		else
			ft_dprintf(2, "Unknown error");
	}
	ft_dprintf(2, "\n");
}
