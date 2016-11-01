/*
** infindiv.c for infindiv in /home/cedric/delivery/CPool_bistro-matic/divinf
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Fri Oct 28 13:28:36 2016 Cédric Thomas
** Last update Tue Nov  1 09:39:01 2016 Cédric Thomas
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
  shifted = malloc(sizeof(char) * (my_strlen(str) + dec + 1)); 
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

t_ci	div_mod(t_ci *nb1, t_ci *nb2)
{
  t_ci	result;
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


t_ci	infindiv(t_ci ci1, t_ci ci2)
{
  t_ci	res;
  char	*result;

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
  return (res);
}
