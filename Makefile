NAME		=	lem-in

SRCDIR		=	srcs
OBJDIR		=	objs
INCDIR		=	includes

SRCNAM		=	main.c \
				anthill_new.c anthill_delete.c \
			 	anthill_start.c anthill_end.c anthill_neighbors.c \
			 	anthill_add_room.c anthill_add_start.c anthill_add_end.c \
			 	anthill_add_pipe.c \
			 	anthill_set_start.c anthill_set_end.c \
			 	anthill_mark.c anthill_unmark.c \
			 	print_path.c anthill_print.c print_room.c move_print.c \
			 	print_error.c \
			 	parse.c parse_map.c \
			 	path_new.c path_delete.c path_remove_ext.c \
			 	solve.c paths_list.c select_paths.c move.c plan_movement.c \
			 	room_delete.c
INCNAM		=	lem_in.h

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -I$(INCDIR) -I $(LIBFTDIR)/includes -D LEM_ERROR_V
LDFLAGS		=	-L $(LIBFTDIR) -l$(LIBFTNAM:lib%.a=%)

GIT			=	README.md Makefile .gitignore auteur

LIBFTDIR	=	~/work/libft
LIBFTNAM	=	libft.a
LIBFT		=	$(LIBFTNAM:%=$(LIBFTDIR)/%)

SRC			=	$(SRCNAM:%=$(SRCDIR)/%)
INC			=	$(INCNAM:%=$(INCDIR)/%)
OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:
	@$(MAKE) $(LIBFTNAM) -C $(LIBFTDIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no check clean fclean re

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)| grep -B1 Error | cat

check: no

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	$(MAKE) all
