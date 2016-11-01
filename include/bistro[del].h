/*
** bistro.h for Bistromathique in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Mon Oct 24 10:18:20 2016 Cédric Thomas
** Last update Tue Nov  1 22:16:46 2016 Arthur Knoepflin
*/

#ifndef BISTRO_H_
# define BISTRO_H_

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_ci
{
  int		s;
  int		l;
  char		*n;
}	t_ci;

int	transfert(t_ci *ci, char *nb);
int	t_ci_cmp(t_ci *nb1, t_ci *nb2);
t_ci	infinadd(t_ci nb1, t_ci nb2);
t_ci	infinsub(t_ci nb1, t_ci nb2);

t_ci	infinmul(t_ci *, t_ci *);

/*
** error.c
*/
void	my_puterror(char *);
int	check_parenthesis(char *);
int	check_errors(char *);

#define	OP_OPEN_PARENT_IDX	0
#define	OP_CLOSE_PARENT_IDX	1
#define	OP_PLUS_IDX		2
#define	OP_SUB_IDX		3
#define	OP_NEG_IDX		3
#define	OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define	OP_MOD_IDX		6

#define	EXIT_USAGE		84
#define	EXIT_BASE		84
#define	EXIT_SIZE_NEG		84
#define	EXIT_MALLOC		84
#define	EXIT_READ		84
#define	EXIT_OPS		84

#define	SYNTAX_ERROR_MSG	"syntax error"
#define	ERROR_MSG		"error"

typedef struct	s_list
{
  char	*b;
  char	*o;
  char	*e;
}	t_list;

/* change_sign.c */

int	get_sign(t_list);
char	*change_sign(t_list);

/* my_str_to_stack */

int	is_operator(char);
int	nb_size(t_list);
int	index_child(t_list, int);
int	size_child(t_list, int);
char	**str_to_stack(t_list);

/* my_str_to_stack_2.c */

int	index_child_2(int, int, t_list);
int	is_nb(char *, t_list);
void	free_all(char **, char **);

/* my_epurstr.c */

static void	int_memset(int *, int);
t_list		my_epurstr(t_list);

/* module_stack.c */

int	is_op(char *, t_list);
void	transfert_stack(char **, char **);
void	swap(char *, char **, char **, int *, t_list);
void	destack(char **, char **, char, t_list);
int	get_stack_size(char **);

/* evalexpr.c */

char	*eval_expr(t_list, unsigned int);

/* in_to_rpn.c */

char	**set_pile(char **, t_list);
char	**set_out(char **, t_list);
int	append_st(char **, char *);
char	*get_last(char **);
char	**in_to_rpn(char **, t_list);

/* do_op.c */

int	get_oper(char *);
int	size_int(int);
char	*toc_alloc(int);
char	*int_toc(int);
char	*do_op(char *, char *, char *);

/* calc.c */

int	get_nb_op(char **, t_list);
char	**copy(char **, char **, t_list);
char	**copy_stack(char **, char **);
char	**free_stack(char **);
int	calc(char **, t_list);

/* calc_fnt */

int	add(t_ci, t_ci);
int	less(t_ci, t_ci);
int	times(t_ci, t_ci);
int	divide(t_ci, t_ci);
int	modulo(t_ci, t_ci);

/* get_oper.c */

int	is_oper(char, char *);
int	is_op_prio(char, char *);
int	is_op_nprio(char, char *);
int	is_number(char, char *);

#define	OP_OPEN_PARENT_IDX	0
#define	OP_CLOSE_PARENT_IDX	1
#define	OP_PLUS_IDX		2
#define	OP_SUB_IDX		3
#define	OP_NEG_IDX		3
#define	OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define	OP_MOD_IDX		6

#define	EXIT_USAGE		84
#define	EXIT_BASE		84
#define	EXIT_SIZE_NEG		84
#define	EXIT_MALLOC		84
#define	EXIT_READ		84
#define	EXIT_OPS		84

#define	SYNTAX_ERROR_MSG	"syntax error"
#define	ERROR_MSG		"error"

#endif /* !BISTRO_H_ */
