/*
** infinadd.c for AddInf in /home/cedric/delivery/CPool_infinadd
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 24 09:00:08 2016 Cédric Thomas
** Last update Mon Oct 31 16:56:09 2016 Cédric Thomas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

static void     check_sign(t_ci *ci1, t_ci *ci2, t_ci *res, int *bool)
{
  *bool = 1;
  if (ci1->s == 1)
    {
      ci1->s = 0;
      *res = infinsub(*ci2, *ci1);
    }
  else
    {
      ci2->s = 0;
      *res = infinsub(*ci1, *ci2);  
    }
}


static char	*add_mod(t_ci *a, t_ci *b, int sign)
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
  int	bool;

  result = NULL;
  bool = 0;
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
    check_sign(&ci1, &ci2, &res, &bool);
  if (bool == 0)
    {
      free(ci1.n);
      free(ci2.n);
    }
  return (res);
}
