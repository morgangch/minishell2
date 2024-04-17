##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Makefile myprintf
##

NAME	=	mysh

SRC	=	src/main.c \
		src/builtin_handler.c \
		src/builtin_checker.c \
		src/command_handling.c \
		src/linked_list_utilities.c \
		src/utilities.c \
		src/env_utilities.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude/

LDFLAGS	=	-L./lib/my -lmy

DBUGFLAGS = -g3

DBUGRUN_LOGNAME = valgrind-out.txt

DBUGRUN_FLAGS = --leak-check=yes --show-leak-kinds=all --track-origins=yes \
				--verbose --log-file=$(DBUGRUN_LOGNAME) \
				--trace-children=yes --track-fds=yes

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(MAKE) -C lib/my clean
		rm -f $(NAME)
		rm -f $(OBJ)

fclean:	clean
		$(MAKE) -C lib/my fclean

re: fclean all

debug: CFLAGS += $(DBUGFLAGS)
debug: $(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(DBUGFLAGS)

debug_re: fclean debug

debug_run: debug_re
	echo "ls\nexit" | valgrind $(DBUGRUN_FLAGS) ./$(NAME)
	cat $(DBUGRUN_LOGNAME)
	echo $$(cat $(DBUGRUN_LOGNAME))
