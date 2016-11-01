/*
** my_str_to_stack.c for str_to_stack in /home/arthur/delivery/CPool_BS_EvalExpr
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 25 11:37:27 2016 Arthur Knoepflin
** Last update Tue Nov  1 22:36:27 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	is_operator(char c)
{
  if (c == '%' || (c >= '(' && c <= '+') ||
      c == '-' || c == '/')
    return (1);
  return (0);
}

int	nb_size(t_list l)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (l.e[i])
    {
      if (i == 0 && is_number(l.e[i], l.b))
	count += 1;
      else if (i > 0 && is_number(l.e[i], l.b) && is_oper(l.e[i - 1], l.o))
	count += 1;
      if (i == 0 && l.e[i] == l.o[OP_OPEN_PARENT_IDX])
	count += 1;
      if (i > 0 && (l.e[i] == l.o[OP_NEG_IDX]))
	if (!is_oper(l.e[i - 1], l.o) || l.e[i - 1] == l.o[OP_CLOSE_PARENT_IDX])
	  count += 1;
	else;
      else if (i > 0 && is_oper(l.e[i], l.o))
	count += 1;
      i += 1;
    }
  return (count);
}

int	index_child(t_list l, int index)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (index == 0)
    return (0);
  while (l.e[i] && count <= index)
    {
      count = index_child_2(count, i, l);
      if (count <= index)
	i += 1;
    }
  if (!is_oper(l.e[i], l.o) && l.e[i - 1] == l.o[OP_NEG_IDX] &&
      (is_oper(l.e[i - 2], l.o) && l.e[i - 2] != l.o[OP_CLOSE_PARENT_IDX]))
    i -= 1;
  return (i);
}

int	size_child(t_list l, int index)
{
  int	i;
  int	count;

  i = index_child(l, index);
  count = 0;
  if (l.e[i] == l.o[OP_NEG_IDX])
    {
      if (i == 0 || (is_oper(l.e[i - 1], l.o) &&
		     l.e[i - 1] != l.o[OP_CLOSE_PARENT_IDX]))
	{
	  i += 1;
	  count += 1;
	}
      else if (!is_oper(l.e[i - 1], l.o))
	return (1);
    }
  if (is_oper(l.e[i], l.o))
    return (1);
  while (is_number(l.e[i], l.b))
    {
      i += 1;
      count += 1;
    }
  return (count);
}

char	**str_to_stack(t_list l)
{
  int	i;
  int	j;
  char	**ret;

  i = 0;
  if ((ret = malloc(sizeof(char *) * (nb_size(l) + 1))) == NULL)
    return (NULL);
  ret[nb_size(l)] = NULL;
  while (i < nb_size(l))
    {
      if ((ret[i] = malloc(sizeof(char) * ((size_child(l, i) + 1)))) == NULL)
	return (NULL);
      ret[i][size_child(l, i)] = '\0';
      j = 0;
      while (j < size_child(l, i))
	{
	  ret[i][j] = l.e[index_child(l, i) + j];
	  j += 1;
	}
      i += 1;
    }
  return (ret);
}
