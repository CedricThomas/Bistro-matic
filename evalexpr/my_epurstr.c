/*
** my_epurstr.c for my_epurstr in /home/cedric/delivery/epurstr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Tue Oct 25 13:55:24 2016 Cédric Thomas
** Last update Tue Nov  1 22:36:05 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

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

t_list	my_epurstr(t_list list)
{
  int	i[2];
  char	*epured;

  int_memset(i, 2);
  while (list.e[i[0]] != '\0')
    {
      if (list.e[i[0]] != ' ')
	i[1] += 1;
      i[0] += 1;
    }
  if ((epured = malloc(sizeof(char) * (i[1] + 2))) == NULL)
    exit(EXIT_MALLOC);
  int_memset(i, 2);
  while (list.e[i[0]] != '\0')
    {
      if (list.e[i[0]] != ' ')
	{
	  epured[i[1]] = list.e[i[0]];
	  i[1] += 1;
	}
      i[0] += 1;
    }
  epured[i[1]] = '\0';
  list.e = epured;
  return (list);
}
