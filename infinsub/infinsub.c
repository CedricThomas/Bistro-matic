/*
** infinsub.c for AddInf in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Mon Oct 24 09:00:08 2016 Cédric Thomas
** Last update Sun Nov  6 19:47:06 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

static void	check_sign(t_ci *ci1, t_ci *ci2, t_ci *res, int *bool)
{
  *bool = 1;
  if (ci2->s == 1)
    {
      ci2->s = 0;
      *res = infinadd(*ci1, *ci2);
    }
  else
    {
      ci2->s = 1;
      *res = infinadd(*ci2, *ci1);
    }
}


static char	*sub_mod(t_ci *a, t_ci *b, int sign)
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
  result = add_retenu(0, a->n, sign, '-');
  return (result);
}

t_ci	infinsub(t_ci ci1, t_ci ci2)
{
  char  *result;
  t_ci	res;
  int	bool;

  result = NULL;
  bool = 0;
  if (ci1.s != ci2.s || ci1.s == ci2.s && ci1.s == 1)
    check_sign(&ci1, &ci2, &res, &bool);
  else if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) == 0)
    char_to_stru(&res, my_strdup("0"));
  else if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) > 0 || ci1.l > ci2.l)
    {
      result = sub_mod(&ci1, &ci2, 0);
      char_to_stru(&res, result);
    }
  else if (ci1.l == ci2.l && my_strcmp(ci1.n, ci2.n) < 0  || ci1.l < ci2.l)
    {
      result = sub_mod(&ci2, &ci1, 1);
      char_to_stru(&res, result);
    }
  if (bool == 0)
    {
      free(ci1.n);
      free(ci2.n);
    }
  return (res);
}
