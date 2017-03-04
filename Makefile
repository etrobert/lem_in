NAME		=	lem-in

COLOR		=	\033[31m
COLOR_RESET	=	\033[0m

SRCDIR		=	srcs
OBJDIR		=	objs
INCDIR		=	includes

SRCNAM		=	main_bonus.c lem_in.c \
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

MAPS		=	maps/error.lem \
				maps/just_ants.lem \
				maps/multi.lem \
				maps/neg.lem \
				maps/nei.lem \
				maps/no_pipe.lem \
				maps/nothing.lem \
				maps/same.lem \
				maps/test.lem \
				maps/test_0.lem

GIT			=	README.md Makefile .gitignore auteur $(MAPS)

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
	@$(MAKE) printname
	@printf "%-15s%s\n" Linking $@
	@$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC)
	@$(MAKE) printname
	@printf "%-15s%s\n" Compiling $@ 
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

printname:
	@printf "$(COLOR)"
	@printf "[%-15s " "$(NAME)]"
	@printf "$(COLOR_RESET)"

.PHONY: all git no check clean fclean re printname

git:
	@$(MAKE) printname
	@echo Adding files to git repository
	git add $(SRC) $(INC) $(GIT)
	@$(MAKE) git -C $(LIBFTDIR)

no:
	@$(MAKE) printname
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)| grep -B1 Error | cat
	@$(MAKE) no -C $(LIBFTDIR)

check: no

clean:
	@$(MAKE) printname
	@echo Suppressing obj files
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) printname
	@echo Suppressing $(NAME)
	@rm -rf $(NAME)

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# cf make -j 
re: fclean
	@$(MAKE) all
