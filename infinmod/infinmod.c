/*
** infindiv.c for infindiv in /home/cedric/delivery/CPool_bistro-matic/divinf
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Sun Nov  6 19:46:48 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

t_ci	mod_mod(t_ci *nb1, t_ci *nb2)
{
  t_ci	result;
  t_ci	addon;
  t_ci	mul;

  char_to_stru(&result, my_strdup("0"));
  while (t_ci_cmp(nb1, nb2) >= 0)
    {
      addon = get_addon(nb1, nb2);
      result = infinadd(result, stru_dup(&addon));
      nb1->l = my_strlen(nb1->n);
      mul = infinmul(stru_dup(nb2), addon);
      *nb1 = infinsub(*nb1, stru_dup(&mul));
      free(mul.n);
    }
  free(result.n);
  free(nb2->n);
  return (*nb1);
}

t_ci	infinmod(t_ci ci1, t_ci ci2)
{
  t_ci	res;
  char	*result;
  int	sign;

  result = NULL;
  if (ci1.s == 1)
    sign = 1;
  else
    sign = 0;
  ci1.s = 0;
  ci2.s = 0;
  res = mod_mod(&ci1, &ci2);
  res.s = sign;
  return (res);
}
