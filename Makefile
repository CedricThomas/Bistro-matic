##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Tue Nov  1 09:22:15 2016 Cédric Thomas
##

SRC	=	infinadd/infinadd.c	\
		infinsub/infinsub.c	\
		infinmul/infinmul.c	\
		infindiv/infindiv.c	\
		main.c			\
		module_bistro.c		\
		convert.c		\
		int_to_char.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bistro

LIB_F	=	./lib/

LIB	=	my

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g	


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIB_F) -l$(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONE: all clean fclean re
