##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Fri Oct 28 13:14:18 2016 Arthur Knoepflin
##

SRC	=	main.c			\
		do_op.c			\
		my_str_to_stack.c	\
		change_sign.c		\
                my_str_to_stack_2.c	\
		in_to_rpn.c		\
		module_stack.c		\
		calc.c			\
		calc_fnt.c		\
		my_epurstr.c		

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

LIB_F	=	lib/

LIB	=	my

INCLUDE	=	-Iinclude/

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
