/*
** module_bistro.c for bistro in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Mon Oct 24 18:25:52 2016 Cédric Thomas
** Last update Sun Nov  6 19:46:37 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

t_ci	stru_dup(t_ci *ci)
{
  t_ci	duped;

  duped.n = my_strdup(ci->n);
  duped.s = ci->s;
  duped.l = my_strlen(ci->n);
  return (duped);
}

int	t_ci_cmp(t_ci *ci1, t_ci *ci2)
{
  if (my_strcmp(ci1->n, ci2->n) == 0 && ci1->s == ci2->s && ci1->l == ci2->l)
    return (0);
  if (ci1->s == ci2->s && ci1->s == 0)
    {
      if (ci1->l == ci2->l && my_strcmp(ci1->n, ci2->n) < 0 || ci1->l < ci2->l)
	return (-1);
      else
	return (1);
    }
  else if (ci1->s == ci2->s && ci1->s == 1)
    {
      if (ci1->l == ci2->l && my_strcmp(ci1->n, ci2->n) > 0 || ci1->l < ci2->l)
	return (-1);
      else
	return (1);
    }
  else
    {
      if (ci1->s == 1)
	return (-1);
      else
	return (1);
    }
}

int	get_nl(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] == '0' && nb[i + 1] != '\0')
    i += 1;
  return (i);
}

char	*add_retenu(int retenu, char *nb, int sign, char mod)
{
  char	*result;
  int	sum;
  int	i;

  if (mod == '-')
    nb = nb + get_nl(nb);
  if (sign != 0 && my_strcmp("0", nb) == 0)
    sign = 0;
  i = sign + retenu;
  sum = retenu + sign + my_strlen(nb);
  if ((result = malloc(sizeof(char) * (sum + 1))) == NULL)
    exit(EXIT_MALLOC);
  if (sign != 0)
    result[0] = '-';
  if (retenu != 0)
    result[sign] = retenu + '0';
  while (i < sum)
    {
      result[i] = nb[i - sign - retenu];
      i += 1;
    }
  result[i] = '\0';
  return (result);
}
