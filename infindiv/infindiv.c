/*
** infindiv.c for infindiv in /home/cedric/delivery/CPool_bistro-matic/divinf
<<<<<<< HEAD
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Tue Nov  1 23:58:50 2016 Arthur Knoepflin
=======
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Tue Nov  1 09:39:01 2016 Cédric Thomas
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
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
<<<<<<< HEAD
  shifted = malloc(sizeof(char) * (my_strlen(str) + dec + 1));
=======
  shifted = malloc(sizeof(char) * (my_strlen(str) + dec + 1)); 
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
  while (i < my_strlen(str) + dec)
    {
      if (str[j] != '\0')
	{
<<<<<<< HEAD
	  shifted[i] = str[j];
=======
	  shifted[i] = str[j]; 
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
	  j += 1;
	}
      else
	shifted[i] = '0';
      i += 1;
    }
  shifted[i] = '\0';
<<<<<<< HEAD
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
=======
  free(str);
  return (shifted);  
}

/* t_ci	get_boost(t_ci *a, t_ci *b) */
/* { */
/*   char	*a1; */
/*   int	ia1; */
/*   char	*b1; */
/*   int	ib1; */
/*   char	*c1; */
/*   int	dec; */
/*   t_ci	c; */

/*   a1 = my_strdup(a->n); */
/*   b1 = my_strdup(b->n); */
/*   a1 = shiftstr(a1, 8 - a->l); */
/*   b1 = shiftstr(b1, 4 - b->l); */
/*   ia1 = my_getnbr(a1); */
/*   ib1 = my_getnbr(b1); */
/*   c1 = int_toc(ia1 / ib1); */
/*   dec = (a->l - my_strlen(a1)) - (b->l - my_strlen(b1)); */
/*   char_to_stru(&c, shiftstr(c1, dec)); */
/*   return (c); */
/* } */
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0

t_ci	div_mod(t_ci *nb1, t_ci *nb2)
{
  t_ci	result;
<<<<<<< HEAD
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

=======
  t_ci	one;
  t_ci	boost;
  
  char_to_stru(&result, my_strdup("0"));
  char_to_stru(&one, my_strdup("1"));
  while (t_ci_cmp(nb1, nb2) != -1)
    {
      result = infinadd(stru_dup(&result), stru_dup(&one));
      *nb1 = infinsub(stru_dup(nb1), stru_dup(nb2));
      nb1->l = my_strlen(nb1->n);
    }
  free(one.n);
  return (result);
}


>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
t_ci	infindiv(t_ci ci1, t_ci ci2)
{
  t_ci	res;
  char	*result;
<<<<<<< HEAD
  int	sign;

  result = NULL;
  if ((ci1.s == 0 && ci2.s == 1) || (ci1.s == 1 && ci2.s == 0))
    sign = 1;
  else
    sign = 0;
  ci1.s = 0;
  ci2.s = 0;
  res = div_mod(&ci1, &ci2);
  res.s = sign;
=======

  result = NULL;
  if (t_ci_cmp(&ci1, &ci2) == -1)
    {
      result = my_strdup("0");
      char_to_stru(&res, result);
    }
  if (t_ci_cmp(&ci1, &ci2) == 0)
    {
      result = my_strdup("1");
      char_to_stru(&res, result);
    }
  else
    res = div_mod(&ci1, &ci2);
  //free(result);
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
  return (res);
}
