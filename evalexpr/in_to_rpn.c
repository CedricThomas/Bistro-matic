/*
** g_s_s.c for g_s_s in /home/arthur/delivery/CPool_BS_EvalExpr/Arthur
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 25 10:51:56 2016 Arthur Knoepflin
** Last update Thu Nov  3 14:18:45 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

char	**set_pile(char **in, char *b)
{
  int	i[2];
  char	**pile;

  i[0] = 0;
  i[1] = 0;
  while (in[i[0]] != 0)
    {
      if (in[i[0]][0] != ')' && !is_nb(in[i[0]], b))
	i[1] += 1;
      i[0] += 1;
    }
  if ((pile = malloc(sizeof(char *) * (i[1] + 1))) == NULL)
    return (NULL);
  i[0] = 0;
  while (i[0] < i[1])
    {
      pile[i[0]] = NULL;
      i[0] += 1;
    }
  pile[i[1]] = 0;
  return (pile);
}

char	**set_out(char **in)
{
  int	i[2];
  char	**out;

  i[0] = 0;
  i[1] = 0;
  while (in[i[0]] != 0)
    {
      if (in[i[0]][0] != ')' && in[i[0]][0] != '(')
	i[1] += 1;
      i[0] += 1;
    }
  if ((out = malloc(sizeof(char *) * (i[1] + 1))) == NULL)
    return (NULL);
  i[0] = 0;
  while (i[0] < i[1])
    {
      out[i[0]] = NULL;
      i[0] += 1;
    }
  out[i[1]] = 0;
  return (out);
}

int	append_st(char **stack, char *token)
{
  int	i;

  i = 0;
  while (stack[i] != NULL && stack[i] != 0)
    i += 1;
  if (stack[i] == NULL)
    {
      stack[i] = token;
      return (1);
    }
  else
    return (0);
}

char	*get_last(char **stack)
{
  int	i;

  i = 0;
  while (stack[i] != NULL && stack[i] != 0)
    i += 1;
  if (i > 0)
    return (stack[i - 1]);
  else
    return (NULL);
}

char	**in_to_rpn(char **in, char *b)
{
  char	**pile;
  char	**out;
  int	i;

  i = 0;
  pile = set_pile(in, b);
  out = set_out(in);
  while (in[i] != 0)
    {
      if (is_nb(in[i], b))
	append_st(out, in[i]);
      else if (in[i][0] == '(')
	append_st(pile, in[i]);
      else if (is_op(in[i]))
	swap(in[i], out, pile, &i);
      else if (in[i][0] == ')')
	{
	  destack(pile, out, '(');
	  free(in[i]);
	}
      i += 1;
    }
  destack(pile, out, '\0');
  free_all(pile, in);
  return (out);
}
