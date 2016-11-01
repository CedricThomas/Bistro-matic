/*
** change_sign.c for change_sign in /home/cedric/CPool_evalexpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Fri Oct 28 10:46:39 2016 Cédric Thomas
** Last update Tue Nov  1 22:35:48 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	gt_sign(t_list list)
{
  int	i;
  int	add;

  i = 0;
  add = 0;
  while (list.e[i] != '\0')
    {
      if (i > 0 && list.e[i] == list.o[OP_OPEN_PARENT_IDX] &&
	  list.e[i - 1] == list.o[OP_NEG_IDX])
	add += 2;
      i += 1;
    }
  return (add);
}

char	*change_sign(t_list l)
{
  char	*dest;
  int	i;
  int	j;

  if ((dest = malloc(sizeof(char) * (my_strlen(l.e) + 1 + gt_sign(l)))) == NULL)
    exit(EXIT_MALLOC);
  i = 0;
  j = 0;
  while (l.e[i] != '\0')
    {
      if ((i + 1) < my_strlen(l.e) && l.e[i] == l.o[OP_NEG_IDX] &&
	  l.e[i + 1] == l.o[OP_OPEN_PARENT_IDX])
	{
	  dest[j] = l.e[i];
	  dest[j + 1] = l.b[1];
	  dest[j + 2] = l.o[OP_MULT_IDX];
	  j += 2;
	}
      else
	dest[j] = l.e[i];
      j += 1;
      i += 1;
    }
  dest[j] = '\0';
  free(l.e);
  return (dest);
}
