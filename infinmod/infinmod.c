/*
** infindiv.c for infindiv in /home/cedric/delivery/CPool_bistro-matic/divinf
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Wed Nov  2 00:20:19 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

t_ci	mod_mod(t_ci *nb1, t_ci *nb2)
{
  t_ci	result;
  t_ci	addon;
  t_ci	mul;
  t_ci	dup2;

  char_to_stru(&result, my_strdup("0"));
  while (t_ci_cmp(nb1, nb2) >= 0)
    {
      addon = get_addon(nb1, nb2);
      result = infinadd(stru_dup(&result), stru_dup(&addon));
      dup2 = stru_dup(nb2);
      nb1->l = my_strlen(nb1->n);
      mul = infinmul(dup2, addon);
      *nb1 = infinsub(stru_dup(nb1), stru_dup(&mul));
    }
  return (*nb1);
}

t_ci	infinmod(t_ci ci1, t_ci ci2)
{
  t_ci	res;

  res = mod_mod(&ci1, &ci2);
  return (res);
}
