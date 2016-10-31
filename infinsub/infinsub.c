/*
** infinadd.c for AddInf in /home/cedric/delivery/CPool_infinadd
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 24 09:00:08 2016 Cédric Thomas
** Last update Mon Oct 31 11:21:16 2016 Cédric Thomas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

static char	*sub_mod(t_ci *a, t_ci *b)
{
  int		i;
  int		o;
  int		retenu;
  char		*result;

  i = a->l - 1;
  retenu = 0;
  while (i >= 0)
    {
      o = b->l - a->l + i;
      a->n[i] = a->n[i] - retenu - ((o >= 0) ? ((b->n[o]) - '0') : 0);
      if (a->n[i] < '0')
	{
	  retenu = 1;
	  a->n[i] += 10;
	}
      else
	retenu = 0;
      i -= 1;
    }
  result = add_retenu(0, a->n, a->s, '-');
  return (result);
}

void	*infinsub(t_ci ci1, t_ci ci2, t_ci *res)
{
  char	*result;


}
