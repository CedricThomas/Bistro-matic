/*
** my_epurstr.c for my_epurstr in /home/cedric/delivery/epurstr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Tue Oct 25 13:55:24 2016 Cédric Thomas
** Last update Thu Oct 27 18:39:08 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

static void	int_memset(int *array, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      array[i] = 0;
      i += 1;
    }
}

char	*my_epurstr(char *str)
{
  int	i[2];
  char	*epured;

  int_memset(i, 2);
  while (str[i[0]] != '\0')
    {
      if (str[i[0]] != ' ')
	i[1] += 1;
      i[0] += 1;
    }
  if ((epured = malloc(sizeof(char) * (i[1] + 2))) == NULL)
    return (NULL);
  int_memset(i, 2);
  while (str[i[0]] != '\0')
    {
      if (str[i[0]] != ' ')
	{
	  epured[i[1]] = str[i[0]];
	  i[1] += 1;
	}
      i[0] += 1;
    }
  epured[i[1]] = '\0';
  return (epured);
}
