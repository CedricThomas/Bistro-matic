/*
** my_str_to_stack_2.c for my_str_to_stack_2 in /home/arthur/delivery/CPool_evalexpr
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Oct 27 15:14:48 2016 Arthur Knoepflin
** Last update Thu Nov  3 14:17:44 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	index_child_2(int count, int i, char *str, char *b)
{
  if (i == 0 && is_number(str[i], b))
    count += 1;
  else if (i > 0 && is_number(str[i], b) && is_operator(str[i - 1]))
    count += 1;
  if (i == 0 && str[i] == '(')
    count += 1;
  if (i > 0 && (str[i] == '-'))
    {
      if (!is_operator(str[i - 1]) || str[i - 1] == ')')
	count += 1;
    }
  else if (i > 0 && is_operator(str[i]))
    count += 1;
  return (count);
}

int	is_nb(char *str, char *b)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_number(str[i], b))
	return (1);
      i += 1;
    }
  return (0);
}

void	free_all(char **pile, char **in)
{
  free(pile);
  free(in);
}
