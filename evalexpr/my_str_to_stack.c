/*
** my_str_to_stack.c for str_to_stack in /home/arthur/delivery/CPool_BS_EvalExpr
**
** Made by Arthur Knoepflin
** Login   <arthur.knoepflin@epitech.net>
**
** Started on  Tue Oct 25 11:37:27 2016 Arthur Knoepflin
** Last update Sun Nov  6 19:48:24 2016 Cebrail Aktas
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

int	nb_size(char *str, char *b)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (i == 0 && is_number(str[i], b))
	count += 1;
      else if (i > 0 && is_number(str[i], b) && is_operator(str[i - 1]))
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

int	index_child(char *str, int index, char *b)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (index == 0)
    return (0);
  while (str[i] && count <= index)
    {
      count = index_child_2(count, i, str, b);
      if (count <= index)
	i += 1;
    }
  if (!is_operator(str[i]) && str[i - 1] == '-' &&
      (is_operator(str[i - 2]) && str[i - 2] != ')'))
    i -= 1;
  return (i);
}

int	size_child(char *str, int index, char *b)
{
  int	i;
  int	count;

  i = index_child(str, index, b);
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
  while (is_number(str[i], b))
    {
      i += 1;
      count += 1;
    }
  return (count);
}

char	**str_to_stack(char *s, char *b)
{
  int	i;
  int	j;
  char	**ret;

  i = 0;
  if ((ret = malloc(sizeof(char *) * (nb_size(s, b) + 1))) == NULL)
    exit(EXIT_MALLOC);
  ret[nb_size(s, b)] = NULL;
  while (i < nb_size(s, b))
    {
      if ((ret[i] = malloc(sizeof(char) * ((size_child(s, i, b) + 1)))) == NULL)
	exit(EXIT_MALLOC);
      ret[i][size_child(s, i, b)] = '\0';
      j = 0;
      while (j < size_child(s, i, b))
	{
	  ret[i][j] = s[index_child(s, i, b) + j];
	  j += 1;
	}
      i += 1;
    }
  return (ret);
}
