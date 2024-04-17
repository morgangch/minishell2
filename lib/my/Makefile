##
## EPITECH PROJECT, 2023
## Day10
## File description:
## Makefile
##

NAME	=	libmy.a

SRCS	=	my_error_handler.c	\
			my_str_islower.c	\
			my_str_isnum.c \
			my_putfloat.c \
			my_sort_int_array.c \
			my_put_nbr_base.c \
			my_strupcase.c \
			my_strlowcase.c \
			my_getnbr.c \
			my_str_isalpha.c \
			my_swap.c \
			my_find_prime_sup.c \
			my_compute_square_root.c \
			my_revstr.c \
			myprintf.c \
			my_compute_power_rec.c \
			my_str_isupper.c \
			my_strncat.c \
			my_strncmp.c \
			my_is_prime.c \
			my_isneg.c \
			my_str_isprintable.c \
			my_strstr.c \
			my_showmem.c \
			my_strcapitalize.c \
			my_showstr.c \
			my_len_nbr.c \
			my_strlen.c	\
			my_strcmp.c	\
			my_put_nbr.c	\
			my_unsigned_nbr.c	\
			my_putchar.c	\
			my_put_err.c	\
			my_strcpy.c	\
			my_putstr.c	\
			my_strncpy.c	\
			my_strcat.c	\
			my_strdup.c \
			str_to_word_array.c

CPPFLAGS = -I../../include

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	cp $(NAME) ../

clean:
	$(RM) -f $(OBJS)
	$(RM) -f *~
	$(RM) -f *.gcno
	$(RM) -f *.gcda

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f ../$(NAME)

re:	fclean all
