/*
** my_str_to_stack.c for str_to_stack in /home/arthur/delivery/CPool_BS_EvalExpr
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 25 11:37:27 2016 Arthur Knoepflin
** Last update Thu Oct 27 18:37:31 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

int	is_operator(char c)
{
  if (c == '%' || (c >= '(' && c <= '+') ||
      c == '-' || c == '/')
    return (1);
  return (0);
}

int	nb_size(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (i == 0 && (str[i] >= '0' && str[i] <= '9'))
	count += 1;
      else if (i > 0 && str[i] >= '0' &&
	       str[i] <= '9' && is_operator(str[i - 1]))
	count += 1;
      if (i == 0 && str[i] == '(')
	count += 1;
      if (i > 0 && (str[i] == '-'))
	if (!is_operator(str[i - 1]) || str[i - 1] == ')')
	  count += 1;
	else;
      else if (i > 0 && is_operator(str[i]))
	count += 1;
      i += 1;
    }
  return (count);
}

int	index_child(char *str, int index)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (index == 0)
    return (0);
  while (str[i] && count <= index)
    {
      count = index_child_2(count, i, str);
      if (count <= index)
	i += 1;
    }
  if (!is_operator(str[i]) && str[i - 1] == '-' &&
      (is_operator(str[i - 2]) && str[i - 2] != ')'))
    i -= 1;
  return (i);
}

int	size_child(char *str, int index)
{
  int	i;
  int	count;

  i = index_child(str, index);
  count = 0;
  if (str[i] == '-')
    {
      if (i == 0 || (is_operator(str[i - 1]) && str[i - 1] != ')'))
	{
	  i += 1;
	  count += 1;
	}
      else if (!is_operator(str[i - 1]))
	return (1);
    }
  if (is_operator(str[i]))
    return (1);
  while (str[i] >= '0' && str[i] <= '9')
    {
      i += 1;
      count += 1;
    }
  return (count);
}

char	**str_to_stack(char *str)
{
  int	i;
  int	j;
  char	**ret;

  i = 0;
  if ((ret = malloc(sizeof(char *) * (nb_size(str) + 1))) == NULL)
    return (NULL);
  ret[nb_size(str)] = NULL;
  while (i < nb_size(str))
    {
      if ((ret[i] = malloc(sizeof(char) * ((size_child(str, i) + 1)))) == NULL)
	return (NULL);
      ret[i][size_child(str, i)] = '\0';
      j = 0;
      while (j < size_child(str, i))
	{
	  ret[i][j] = str[index_child(str, i) + j];
	  j += 1;
	}
      i += 1;
    }
  return (ret);
}
