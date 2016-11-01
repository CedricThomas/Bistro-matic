/*
** module_operateur.c for mod_op in /home/cedric/CPool_EvalExpr
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Tue Oct 25 18:01:49 2016 Cédric Thomas
** Last update Tue Nov  1 22:36:53 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	is_op(char *str, t_list l)
{
  char	c;

  c = str[0];
  if (c != l.o[OP_PLUS_IDX] && c != l.o[OP_SUB_IDX])
    if (c != l.o[OP_DIV_IDX] && c != l.o[OP_MULT_IDX])
      if (c != l.o[OP_MOD_IDX])
	return (0);
  if (my_strlen(str) == 1)
    return (1);
  else
    return (0);
}

void	transfert_stack(char **stack1, char **stack2)
{
  int	i;

  i = 0;
  while (stack1[i] != NULL && stack1[i] != 0)
    i += 1;
  if (i > 0)
    {
      append_st(stack2, stack1[i - 1]);
      stack1[i - 1] = NULL;
    }
}

void	swap(char *in, char **out, char **pile, int *count, t_list l)
{
  char	*last;
  int   i;

  i = 0;
  if ((last = get_last(pile)) == NULL)
    {
      append_st(pile, in);
      return ;
    }
  if (is_op_prio(last[0], l.o) && is_op_nprio(last[0], l.o) ||
      is_op_prio(last[0], l.o) && is_op_prio(last[0], l.o) ||
      is_op_nprio(last[0], l.o) && is_op_nprio(last[0], l.o))
    {
      transfert_stack(pile, out);
      if (count > 0 && get_last(pile) != NULL && get_last(pile)[0] != '(')
	*count -= 1;
      else
	append_st(pile, in);
    }
  else
    append_st(pile, in);
}

void	destack(char **pile, char **out, char c, t_list l)
{
  int	size;

  size = get_stack_size(pile) - 1;
  while (size >= 0 && pile[size][0] != c)
    {
      transfert_stack(pile, out);
      size -= 1;
    }
  if (c == l.o[OP_OPEN_PARENT_IDX] && pile[size][0] == c)
    {
      free(pile[size]);
      pile[size] = NULL;
    }
}

int	get_stack_size(char **stack)
{
  int	i;

  i = 0;
  while (stack[i] != 0 && stack[i] != NULL)
    i += 1;
  return (i);
}
