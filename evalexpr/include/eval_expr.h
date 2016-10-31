/*
** evalexpr.h for evalexpr.h in /home/cedric/CPool_EvalExpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Wed Oct 26 14:44:54 2016 Cédric Thomas
** Last update Fri Oct 28 13:17:29 2016 Arthur Knoepflin
*/

/* change_sign.c */

int	get_sign(char *);
char	*change_sign(char *);

/* my_str_to_stack */

int	is_operator(char);
int	nb_size(char *);
int	index_child(char *, int);
int	size_child(char *, int);
char	**str_to_stack(char *);

/* my_str_to_stack_2.c */

int	index_child_2(int, int, char *);
int	is_nb(char *);
void	free_all(char **, char **);

/* my_epurstr.c */

static void	int_memset(int *, int);
char		*my_epurstr(char *);

/* module_stack.c */

int	is_op(char *);
void	transfert_stack(char **, char **);
void	swap(char *, char **, char **, int *);
void	destack(char **, char **, char);
int	get_stack_size(char **);

/* main.c */

int	eval_expr(char *);

/* in_to_rpn.c */

char	**set_pile(char **);
char	**set_out(char **);
int	append_st(char **, char *);
char	*get_last(char **);
char	**in_to_rpn(char **);

/* do_op.c */

int	get_oper(char *);
int	size_int(int);
char	*toc_alloc(int);
char	*int_toc(int);
char	*do_op(char *, char *, char *);

/* calc.c */

int	get_nb_op(char **);
char	**copy(char **, char **);
char	**copy_stack(char **, char **);
char	**free_stack(char **);
int	calc(char **);

/* calc_fnt */

int	add(int, int);
int	less(int, int);
int	times(int, int);
int	divide(int, int);
int	modulo(int, int);
