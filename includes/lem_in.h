/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:15:55 by etrobert          #+#    #+#             */
/*   Updated: 2017/01/29 19:57:16 by etrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# ifdef LEM_ERROR_V
#  define LEM_ERROR_V_ON true
# else
#  define LEM_ERROR_V_ON false
# endif

# define EMPTY_ROOM 0

# define LEM_ERR_NO_PATH -1
# define LEM_ERR_NO_START_END -2
# define LEM_ERR_MALLOC -3
# define LEM_ERR_PARSING -4
# define LEM_ERR_OPEN -5

# include <stdbool.h>
# include "libft.h"

typedef struct	s_pstate
{
	bool		start;
	bool		end;
}				t_pstate;

typedef struct	s_room
{
	char		*name;
	bool		marked;
	int			ant;
	t_list		*neighbors;
}				t_room;

/*
typedef struct	s_pipe
{
	t_room		*room1;
	t_room		*room2;
}				t_pipe;
*/

typedef struct	s_anthill
{
	t_room		*start;
	t_room		*end;
	t_list		*rooms;
//	t_list		*pipes;
	int			ants;
}				t_anthill;

typedef struct	s_path
{
	t_list		*path;
	int			ants_to_go;
}				t_path;

int				lem_in(int fd);

/*
** Anthill functions
*/

t_anthill		*anthill_new(void);
void			anthill_delete(t_anthill *anthill);

t_room			*anthill_start(t_anthill *anthill);
bool			anthill_end(t_anthill *anthill, t_room *room);

t_list			*anthill_neighbors(t_anthill *anthill, t_room *room);

int				anthill_add_room(t_anthill *anthill, char *name);
int				anthill_add_start(t_anthill *anthill, char *name);
int				anthill_add_end(t_anthill *anthill, char *name);
int				anthill_add_pipe(t_anthill *anthill, char *room1, char *room2);

void			anthill_set_start(t_anthill *anthill, char *name);
void			anthill_set_end(t_anthill *anthill, char *name);

void			anthill_mark(t_anthill *anthill, t_room *room);
void			anthill_unmark(t_anthill *anthill, t_room *room);

/*
** Print functions
*/

void			print_path(t_path *path);
void			anthill_print(int fd, t_anthill *anthill);
void			print_room(t_room *room);
void			move_print(int ant, t_room *room, bool *start);
void			print_error(int n);

/*
** Parsing
*/

t_anthill		*parse(int fd, t_list *log);
int				parse_map(int fd, t_anthill *anthill, t_list *log);

/*
** Path functions
*/

t_path			*path_new(t_list *path);
void			path_delete(t_path *path);
void			path_remove_ext(t_path *path);
bool			path_common_room(t_list *l1, t_list *l2);

/*
** Solving function
*/

int				solve(t_anthill *anthill, t_list *log);
t_list			*paths_list(t_anthill *anthill);
t_list			*select_paths(const t_list *paths);
void			plan_movement(t_anthill *anthill, t_list *paths);
void			move(t_anthill *anthill, t_list *paths);
int				update_paths(t_list *paths, t_list *new_path);

/*
** Other
*/

void			room_delete(t_room *room);

#endif
