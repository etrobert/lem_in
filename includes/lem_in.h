/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:15:55 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/09 16:21:00 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdbool.h>
# include "libft.h"

typedef struct	s_room
{
	char		*name;
	bool		marked;
}				t_room;

typedef struct	s_pipe
{
	t_room		*room1;
	t_room		*room2;
}				t_pipe;

typedef struct	s_anthill
{
	t_room		*start;
	t_room		*end;
	t_list		*rooms;
	t_list		*pipes;
}				t_anthill;

t_room			*anthill_start(t_anthill *anthill);
bool			anthill_end(t_anthill *anthill, t_room *room);
void			anthill_mark(t_anthill *anthill, t_room *room);
void			anthill_unmark(t_anthill *anthill, t_room *room);
t_list			*anthill_neighbors(t_anthill *anthill, t_room *room);

t_list			*paths_list(t_anthill *anthill);

#endif
