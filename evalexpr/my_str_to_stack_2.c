/*
** my_str_to_stack_2.c for my_str_to_stack_2 in /home/arthur/delivery/CPool_evalexpr
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Oct 27 15:14:48 2016 Arthur Knoepflin
** Last update Tue Nov  1 22:36:37 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	index_child_2(int count, int i, t_list l)
{
  if (i == 0 && is_number(l.e[i], l.b))
    count += 1;
  else if (i > 0 && is_number(l.e[i], l.b) && is_oper(l.e[i - 1], l.o))
    count += 1;
  if (i == 0 && l.e[i] == l.o[OP_OPEN_PARENT_IDX])
    count += 1;
  if (i > 0 && (l.e[i] == l.o[OP_NEG_IDX]))
    {
      if (!is_oper(l.e[i - 1], l.o) || l.e[i - 1] == l.o[OP_OPEN_PARENT_IDX])
	count += 1;
    }
  else if (i > 0 && is_oper(l.e[i], l.o))
    count += 1;
  return (count);
}

int	is_nb(char *str, t_list l)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (is_number(str[i], l.b))
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
