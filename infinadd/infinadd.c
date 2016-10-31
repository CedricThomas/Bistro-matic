/*
** infinadd.c for AddInf in /home/cedric/delivery/CPool_infinadd
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 24 09:00:08 2016 Cédric Thomas
** Last update Mon Oct 31 13:48:24 2016 Cédric Thomas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

static char	*add_mod(t_ci *a, t_ci *b, int sign)
{
  int		i;
  int		o;
  int		retenu;
  char		*result;

  i = a->l - 1;
  retenu = 0;
  printf("sub : %s, %s, %d\n",a->n,b->n,a->s);
  while (i >= 0)
    {
      o = b->l - a->l + i;
      a->n[i] += retenu;
      retenu = (a->n[i] - 48 + (o >= 0 ? b->n[o] - 48 : 0)) / 10;
      a->n[i] = (a->n[i] - 48 + (o >= 0 ? b->n[o] - 48 : 0)) % 10 + '0';
      i -= 1;
    }
  result = add_retenu(retenu, a->n, sign, '+');
  return (result);
}

t_ci	infinadd(t_ci ci1, t_ci ci2)
{
  char	*result;
  t_ci	res;

  if (ci1.l >= ci2.l && ci1.s == ci2.s)
    {
      result = add_mod(&ci1, &ci2, ci1.s);
      char_to_stru(&res, result);
    }
  else if (ci1.l < ci2.l && ci1.s == ci2.s)
    {
      result = add_mod(&ci2, &ci1, ci1.s);
      char_to_stru(&res, result);
    }
  else
    {
      if (ci1.s == 1)
	{
	  res = infinsub(ci2, ci1);
	}
      else
	{
	  res = infinsub(ci1, ci2);  
	}
    }
  return (res);
}
