/*
** g_s_s.c for g_s_s in /home/arthur/delivery/CPool_BS_EvalExpr/Arthur
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 25 10:51:56 2016 Arthur Knoepflin
** Last update Tue Nov  1 22:38:12 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

char	**set_pile(char **in, t_list l)
{
  int	i[2];
  char	**pile;

  i[0] = 0;
  i[1] = 0;
  while (in[i[0]] != 0)
    {
      if (in[i[0]][0] != l.o[OP_CLOSE_PARENT_IDX] && !is_nb(in[i[0]], l))
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

char	**set_out(char **in, t_list l)
{
  int	i[2];
  char	**out;

  i[0] = 0;
  i[1] = 0;
  while (in[i[0]] != 0)
    {
      if (in[i[0]][0] != l.o[OP_CLOSE_PARENT_IDX] &&
	  in[i[0]][0] != l.o[OP_OPEN_PARENT_IDX])
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

char	**in_to_rpn(char **in, t_list l)
{
  char	**pile;
  char	**out;
  int	i;

  i = 0;
  pile = set_pile(in, l);
  out = set_out(in, l);
  while (in[i] != 0)
    {
      if (is_nb(in[i], l))
	append_st(out, in[i]);
      else if (in[i][0] == l.o[OP_OPEN_PARENT_IDX])
	append_st(pile, in[i]);
      else if (is_op(in[i], l))
      	swap(in[i], out, pile, &i, l);
      else if (in[i][0] == l.o[OP_CLOSE_PARENT_IDX])
      	{
      	  destack(pile, out, l.o[OP_OPEN_PARENT_IDX], l);
      	  free(in[i]);
      	}
      i += 1;
    }
  destack(pile, out, '\0', l);
  free_all(pile, in);
  return (out);
}
