/*
** infindiv.c for infindiv in /home/cedric/delivery/CPool_bistro-matic/divinf
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Fri Nov  4 15:22:11 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

char	*shiftstr(char *str, int dec)
{
  char	*shifted;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((shifted = malloc(sizeof(char) * (my_strlen(str) + dec + 1))) == NULL)
    exit(EXIT_MALLOC);
  while (i < my_strlen(str) + dec)
    {
      if (str[j] != '\0')
	{
	  shifted[i] = str[j];
	  j += 1;
	}
      else
	shifted[i] = '0';
      i += 1;
    }
  shifted[i] = '\0';
  return (shifted);
}

t_ci	get_addon(t_ci *nb1, t_ci *nb2)
{
  char	*dupa;
  char	*dupb;
  char	*c1;
  t_ci	c;
  int	dec;

  if (nb1->l > 8)
    dupa = shiftstr(nb1->n, 8 - nb1->l);
  else
    dupa = my_strdup(nb1->n);
  if (nb2->l > 6)
    dupb = shiftstr(nb2->n, 6 - nb2->l);
  else
    dupb = my_strdup(nb2->n);
  c1 = int_toc(my_getnbr(dupa) / (my_getnbr(dupb)));
  dec = (nb1->l - my_strlen(dupa)) - (nb2->l - my_strlen(dupb));
  char_to_stru(&c, shiftstr(c1, dec));
  return (c);
}

t_ci	div_mod(t_ci *nb1, t_ci *nb2)
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
  return (result);
}

t_ci	infindiv(t_ci ci1, t_ci ci2)
{
  t_ci	res;
  char	*result;
  int	sign;

  result = NULL;
  if (my_strcmp(ci2.n, "0") == 0)
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_OPS);
    }
  if ((ci1.s == 0 && ci2.s == 1) || (ci1.s == 1 && ci2.s == 0))
    sign = 1;
  else
    sign = 0;
  ci1.s = 0;
  ci2.s = 0;
  res = div_mod(&ci1, &ci2);
  res.s = sign;
  return (res);
}
