/*
** calc.c for evalexpr in /home/cedric/CPool_EvalExpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Tue Oct 25 20:41:56 2016 Cédric Thomas
** Last update Fri Nov  4 15:20:12 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	get_nb_op(char **str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (my_strlen(str[i]) == 1 && is_op(str[i]))
	count += 1;
      i += 1;
    }
  return (count);
}

char	**copy(char **stack, char **cpy, char *b)
{
  int	i;
  int	j;
  int	bool;

  i = 0;
  j = 0;
  bool = 1;
  while (i < get_stack_size(stack))
    {
      if (bool && (i + 2) < get_stack_size(stack)
	  && is_op(stack[i + 2]))
	{
	  cpy[j] = do_op(stack[i], stack[i + 1], stack[i + 2], b);
	  i += 2;
	  bool = 0;
	}
      else
	cpy[j] = my_strdup(stack[i]);
      i += 1;
      j += 1;
    }
  cpy[j] = 0;
  return (cpy);
}

char	**copy_stack(char **dest, char **src)
{
  int	i;
  int	len;

  len = get_stack_size(src);
  i = 0;
  if ((dest = malloc(sizeof(char *) * (len + 1))) == NULL)
    exit(EXIT_MALLOC);
  while (src[i] != 0)
    {
      dest[i] = my_strdup(src[i]);
      i += 1;
    }
  dest[i] = 0;
  return (dest);
}

char	**free_stack(char **stack)
{
  int	i;

  i = 0;
  while (stack[i] != 0)
    {
      free(stack[i]);
      i += 1;
    }
  free(stack);
  return (stack);
}

char	*calc(char **str, char *b)
{
  int	i;
  char	*result;
  int	l_stack;
  char	**cpy;

  l_stack = get_stack_size(str);
  while (get_nb_op(str))
    {
      l_stack -= 1;
      if ((cpy = malloc(sizeof(char *) * (l_stack + 1))) == NULL)
	exit(EXIT_MALLOC);
      cpy = copy(str, cpy, b);
      str = free_stack(str);
      str = copy_stack(str, cpy);
      cpy = free_stack(cpy);
    }
  result = my_strdup(str[0]);
  free_stack(str);
  return (result);
}
