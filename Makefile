##
## Makefile for Makefile in /home/cedric/lib
##
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
##
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Fri Nov  4 15:29:44 2016 Arthur Knoepflin
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
		evalexpr/convert.c		\
		err_handle/check_base.c		\
		err_handle/check_doubles.c	\
		err_handle/error.c		\
		err_handle/check_parent.c	\
		err_handle/op_destructor.c	\
		err_handle/check_blank.c	\
		err_handle/check_expr.c		\
		infinbase.c			\
		module_bistro.c			\
		main.c

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
