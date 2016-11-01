/*
** evalexpr.h for evalexpr.h in /home/cedric/CPool_EvalExpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
<<<<<<< HEAD
** Started on  Wed Oct 26 14:44:54 2016 Cédric Thomas
** Last update Wed Nov  2 00:18:19 2016 Arthur Knoepflin
=======
** Started on  Mon Oct 24 10:18:20 2016 Cédric Thomas
<<<<<<< HEAD
** Last update Tue Nov  1 09:28:07 2016 Cédric Thomas
=======
** Last update Mon Oct 31 12:04:06 2016 Cebrail Aktas
>>>>>>> 601521785ae3bf39eea882e5b6ccdf3c93d563e1
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
*/

#ifndef EVAL_EXPR_H_
# define EVAL_EXPR_H_

typedef struct	s_list
{
  char	*b;
  char	*o;
  char	*e;
}	t_list;

typedef	struct	s_ci
{
  int	s;
  int	l;
  char	*n;
}	t_ci;

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
char	*calc(char **, t_list);

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

/* module_bistro.c */

int	get_nl(char *);
char	*add_retenu(int, char *, int, char);
t_ci	stru_dup(t_ci *stru);

/* evalexpr/convert.c */

int	char_to_stru(t_ci *, char *);
char	*stru_to_char_malloc(t_ci *);
char	*stru_to_char(t_ci *);

/* convert.c */

static char	*my_strndup(char *, int);
int		char_to_stru(t_ci *, char *);

/* infin_add */

static void	check_sign(t_ci *, t_ci *, t_ci *);
static char	*add_mod(t_ci *, t_ci *, int);
t_ci		infinadd(t_ci, t_ci);

/* infin_sub */

static void	check_sign(t_ci *, t_ci *, t_ci *);
static char	*sub_mod(t_ci *, t_ci *, int);
t_ci		infinsub(t_ci, t_ci);

/* infin_mul */

int	stl(char *);
void	clear_str(t_ci *);
void	calc_neg(t_ci *, t_ci *, t_ci *);
char	*infinmul_calc(t_ci *, t_ci *);
t_ci	infinmul(t_ci, t_ci);

/* infin_div */

char	*shiftstr(char *, int);
t_ci	get_addon(t_ci *, t_ci *);
t_ci	div_mod(t_ci *, t_ci *);
t_ci	infindiv(t_ci, t_ci);

/* infin_mod */

t_ci	mod_mod(t_ci *, t_ci *);
t_ci	infinmod(t_ci, t_ci);

int	t_ci_cmp(t_ci *nb1, t_ci *nb2);
<<<<<<< HEAD

#define	OP_OPEN_PARENT_IDX	0
#define	OP_CLOSE_PARENT_IDX	1
#define	OP_PLUS_IDX		2
#define	OP_SUB_IDX		3
#define	OP_NEG_IDX		3
#define	OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define	OP_MOD_IDX		6
=======
t_ci	infinadd(t_ci nb1, t_ci nb2);
t_ci	infinsub(t_ci nb1, t_ci nb2);
t_ci	infindiv(t_ci nb1, t_ci nb2);
t_ci	infinmul(t_ci *, t_ci *);
t_ci	stru_dup(t_ci *);
t_ci	get_boost(t_ci *, t_ci *);
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0

#define	EXIT_USAGE		84
#define	EXIT_BASE		84
#define	EXIT_SIZE_NEG		84
#define	EXIT_MALLOC		84
#define	EXIT_READ		84
#define	EXIT_OPS		84

#define	SYNTAX_ERROR_MSG	"syntax error"
#define	ERROR_MSG		"error"

#endif /* !EVAL_EXPR_H_ */
