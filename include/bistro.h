/*
** evalexpr.h for evalexpr.h in /home/cedric/CPool_EvalExpr
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Wed Oct 26 14:44:54 2016 Cédric Thomas
** Last update Sun Nov  6 19:47:19 2016 Cebrail Aktas
*/

#ifndef EVAL_EXPR_H_
# define EVAL_EXPR_H_

typedef	struct	s_char_to_int
{
  int		s;
  int		l;
  char		*n;
}		t_ci;

/*
** change_sign.c
*/
int		get_sign(char *);
char		*change_sign(char *);
char		*get_oper_norm();
int		is_opera(char, char *);
char		*change_op(char *, char *);

/*
my_str_to_stack.c
*/
int		is_operator(char);
int		nb_size(char *, char *);
int		index_child(char *, int, char *);
int		size_child(char *, int, char *);
char		**str_to_stack(char *, char *);

/*
** my_str_to_stack_2.c
*/
int		index_child_2(int, int, char *, char *);
int		is_nb(char *, char *);
void		free_all(char **, char **);

/*
** my_epurstr.c
*/
static void	int_memset(int *, int);
char		*my_epurstr(char *);

/*
** module_stack.c
*/

int		is_op(char *);
void		transfert_stack(char **, char **);
void		swap(char *, char **, char **, int *);
void		destack(char **, char **, char);
int		get_stack_size(char **);

/*
** evalexpr.c
*/
char		*eval_expr(char *, char *, char *);

/*
** in_to_rpn.c
*/
char		**set_pile(char **, char *);
char		**set_out(char **);
int		append_st(char **, char *);
char		*get_last(char **);
char		**in_to_rpn(char **, char *);

/*
** do_op.c
*/
int		get_oper(char *);
int		size_int(int);
char		*toc_alloc(int);
char		*int_toc(int);
char		*do_op(char *, char *, char *, char *);

/*
** calc.c
*/
int		get_nb_op(char **);
char		**copy(char **, char **, char *);
char		**copy_stack(char **, char **);
char		**free_stack(char **);
char		*calc(char **, char *);

/*
** calc_fnt.c
*/
int		add(t_ci, t_ci);
int		less(t_ci, t_ci);
int		times(t_ci, t_ci);
int		divide(t_ci, t_ci);
int		modulo(t_ci, t_ci);

/*
** get_oper.c
*/
int		is_number(char, char *);

/*
** module_bistro.c
*/
int		get_nl(char *);
char		*add_retenu(int, char *, int, char);
t_ci		stru_dup(t_ci *stru);

/*
** evalexpr/convert.c
*/
int		char_to_stru(t_ci *, char *);
char		*stru_to_char_malloc(t_ci *);
char		*stru_to_char(t_ci *);

/*
** infinbase.c
*/
t_ci		infinbase(t_ci *, char *, char*);
t_ci		t_ci_dec(t_ci *, char *);
t_ci		t_ci_base(t_ci *, char *, t_ci *, int);
t_ci		search(char *, char);
void		trifree(t_ci *, t_ci *, t_ci *);

/*
** convert.c
*/
static char	*my_strndup(char *, int);
int		char_to_stru(t_ci *, char *);
int		t_ci_cmp(t_ci *, t_ci *);

/*
** infin_add.c
*/
static void	check_sign(t_ci *, t_ci *, t_ci *, int *);
static char	*add_mod(t_ci *, t_ci *, int);
t_ci		infinadd(t_ci, t_ci);

/*
** infin_sub.c
*/
static void	check_sign(t_ci *, t_ci *, t_ci *, int *);
static char	*sub_mod(t_ci *, t_ci *, int);
t_ci		infinsub(t_ci, t_ci);

/*
** infin_mul.c
*/

int		stl(char *);
void		clear_str(t_ci *);
void		calc_neg(t_ci *, t_ci *, t_ci *);
char		*infinmul_calc(t_ci *, t_ci *);
t_ci		infinmul(t_ci, t_ci);

/*
** infin_div.c
*/

char		*shiftstr(char *, int);
t_ci		get_addon(t_ci *, t_ci *);
t_ci		div_mod(t_ci *, t_ci *);
t_ci		infindiv(t_ci, t_ci);

/*
** infin_mod.c
*/

t_ci		mod_mod(t_ci *, t_ci *);
t_ci		infinmod(t_ci, t_ci);

/*
** op_destructor.c
*/
static int	op_get_nbop(char *, int);
static int	op_get_parity(char *, int);
static int	op_get_size(char *);
static char	*del_plus(char *, int, int, int);
char		*opsup(char *);

/*
** check_parent.c
*/
void		check_parent(char *);
void		stop();
void		treat_op(char *, int *);
void		check_syntax(char *, char *);

/*
** check_base.c
*/
int		check_spaces(char *);
int		check_base_ops(char *, char *);
int		check_ops_in_calc(char *, char *);

/*
** check_blank.c
*/
int		valide(char);
void		check_blank(char *, char *);

/*
** check_doubles.c
*/
int		check_double_ops(char *);
int		check_double_base(char *);

/*
** check_expr.c
*/
int		search_c(char *, char);
static int	check_same(char *, char *);
void		check_expr(char *, char *, char *);

/*
** error.c
*/
void		my_puterror(char *);
int		my_is_op(char);
int		check_parenthesis(char *);
int		check_op(char *);
int		check_errors(char *, char *, char *);

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

#endif /* !EVAL_EXPR_H_ */
