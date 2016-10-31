/*
** infinsub.c for AddInf in /home/cedric/delivery/CPool_infinadd
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 24 09:00:08 2016 Cédric Thomas
** Last update Mon Oct 31 14:00:21 2016 Cédric Thomas
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
  printf("sub : %s, %s, %d\n",a->n,b->n,a->s);
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

t_ci	infinsub(t_ci ci1, t_ci ci2)
{
  char  *result;
  t_ci	res;

  if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) == 0)
      char_to_stru(&res, "0");
  else if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) > 0 || ci1.l > ci2.l)
    {
      printf("test1\n");
      result = sub_mod(&ci1, &ci2);
      char_to_stru(&res, result);
    }
  else if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) < 0  || ci1.l < ci2.l)
    {
      printf("test2\n");
      result = sub_mod(&ci2, &ci1);
      char_to_stru(&res, result);
     }
  else
    {
      if (ci2.s == 1)
	{
     	  res = infinadd(ci1, ci2);
	}
      else
	{
	  res = infinadd(ci2, ci1);
	}
    }
  return (res);
}
