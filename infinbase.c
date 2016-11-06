/*
** infinbase.c for infinbase.c in /home/cedric/convert_base
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Wed Nov  2 09:32:01 2016 Cédric Thomas
** Last update Sun Nov  6 19:46:28 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

void	trifree(t_ci *a, t_ci *b, t_ci *c)
{
  free(a->n);
  free(b->n);
  free(c->n);
}

 t_ci	search(char *base, char c)
{
  int	i;
  t_ci	index;

  i = 0;
  while (base[i] != c && base[i] != '\0')
    i += 1;
  char_to_stru(&index, int_toc(i));
  return (index);
}

t_ci	t_ci_base(t_ci *nbr, char *b_to, t_ci *futur, int len)
{
  t_ci	div;
  t_ci	null;
  t_ci	modulo;

  char_to_stru(&null, my_strdup("0"));
  char_to_stru(&div, my_strdup(nbr->n));
  char_to_stru(&modulo, int_toc(my_strlen(b_to)));
  div = infindiv(div, modulo);
  if (t_ci_cmp(&div, &null) > 0)
    {
      *futur = t_ci_base(&div, b_to, futur, len + 1);
    }
  else
    {
      if ((futur->n = malloc(sizeof(char) * (len + 2))) == NULL)
	exit(EXIT_MALLOC);
      futur->n[len + 1] = '\0';
      futur->n[len] = b_to[my_getnbr(infinmod(*nbr, modulo).n)];
      trifree(&null, &div, &modulo);
      return (*futur);
    }
  futur->n[len] = b_to[my_getnbr(infinmod(*nbr, modulo).n)];
  trifree(&null, &div, &modulo);
  return (*futur);
}

t_ci	t_ci_dec(t_ci *nbr, char *b_from)
{
  int	i;
  t_ci	sh;
  t_ci	converted;
  t_ci	lenbase;

  i = 0;
  char_to_stru(&converted, my_strdup("0"));
  while (nbr->n[i] != 0)
    {
      sh = search(b_from, nbr->n[i]);
      char_to_stru(&lenbase, int_toc(my_strlen(b_from)));
      converted = infinmul(converted, lenbase);
      converted = infinadd(stru_dup(&converted), stru_dup(&sh));
      free(sh.n);
      i += 1;
    }
  return (converted);
}

t_ci	infinbase(t_ci *nbr, char *b_from, char *b_to)
{
  t_ci	temp;
  t_ci	converted;

  converted.n = NULL;
  temp = t_ci_dec(nbr, b_from);
  converted = t_ci_base(&temp, b_to, &converted, 0);
  converted.n = my_revstr(converted.n);
  converted.l = my_strlen(converted.n);
  converted.s = nbr->s;
  free(nbr->n);
  free(temp.n);
  return (converted);
}
