/*
** module_operateur.c for mod_op in /home/cedric/CPool_EvalExpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Tue Oct 25 18:01:49 2016 Cédric Thomas
** Last update Wed Nov  2 21:58:00 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	is_op(char *str)
{
  char	c;

  c = str[0];
  if (c != '+' && c != '-')
    if (c != '/' && c != '*')
      if (c != '%')
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

void	swap(char *in, char **out, char **pile, int *count)
{
  char	*last;
  int   i;

  i = 0;
  if ((last = get_last(pile)) == NULL)
    {
      append_st(pile, in);
      return ;
    }
  if ((last[0] == '/' || last[0] == '*' || last[0] == '%')
      && (in[0] == '-' || in[0] == '+') ||
      (last[0] == '/' || last[0] == '*' || last[0] == '%')
      && (in[0] == '/' || in[0] == '*' || in[0] == '%') ||
      ((in[0] == '-' || in[0] == '+') && (last[0] == '-' || last[0] == '+')))
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

void	destack(char **pile, char **out, char c)
{
  int	size;

  size = get_stack_size(pile) - 1;
  while (size >= 0 && pile[size][0] != c)
    {
      transfert_stack(pile, out);
      size -= 1;
    }
  if (c == '(' && pile[size][0] == c)
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
