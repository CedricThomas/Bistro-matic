/*
** do-op.c for do-op in /home/arthur/delivery/CPool_EvalExpr
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Oct 25 22:43:58 2016 Arthur Knoepflin
** Last update Tue Nov  1 09:20:51 2016 Cédric Thomas
*/
#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	size_int(int nb)
{
  int   i;

  i = 0;
  if (nb == 0)
    return (1);
  while (nb != 0)
    {
      nb = nb / 10;
      i += 1;
    }
  return (i);
}

char	*toc_alloc(int nb)
{
  char  *ret;
  if (nb < 0)
    {
      if ((ret = malloc(sizeof(char) * (size_int(nb) + 2))) == NULL)
	return (NULL);
      ret[0] = '-';
      nb *= (-1);
    }
  else
    {
      if ((ret = malloc(sizeof(char) * (size_int(nb) + 1))) == NULL)
	return (NULL);
    }
  return (ret);
}

char	*int_toc(int nb)
{
  int   i[2];
  char  *ret;

  i[0] = 1;
  i[1] = size_int(nb);
  ret = toc_alloc(nb);
  if (ret == NULL)
    return (NULL);
  if (nb < 0)
    {
      nb *= (-1);
      ret[size_int(nb) + 1] = '\0';
    }
  else
    {
      i[1] -= 1;
      ret[size_int(nb)] = '\0';
    }
  while (i[0] <= size_int(nb))
    {
      ret[i[1]] = (nb / my_power_rec(10, i[0] - 1) % 10) + 48;
      i[1] -= 1;
      i[0] += 1;
    }
  if (nb == 0)
    ret[0] = '0';
  return (ret);
}
