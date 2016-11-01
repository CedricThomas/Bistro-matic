##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
<<<<<<< HEAD
## Last update Wed Nov  2 00:15:55 2016 Arthur Knoepflin
##

SRC	=	infinadd/infinadd.c		\
		infinsub/infinsub.c		\
		infinmul/infinmul.c		\
		infindiv/infindiv.c		\
		infinmod/infinmod.c		\
		evalexpr/evalexpr.c		\
		evalexpr/change_sign.c		\
		evalexpr/my_epurstr.c		\
		evalexpr/my_str_to_stack.c	\
		evalexpr/my_str_to_stack_2.c	\
		evalexpr/module_stack.c		\
		evalexpr/get_oper.c		\
		evalexpr/in_to_rpn.c		\
		evalexpr/calc.c			\
		evalexpr/do_op.c		\
		main.c				\
		convert.c			\
		module_bistro.c
=======
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
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

LIB_F	=	./lib/

LIB	=	my

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -g


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIB_F) -l$(LIB)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re
