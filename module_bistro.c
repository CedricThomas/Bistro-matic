/*
** module_bistro.c for bistro in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Mon Oct 24 18:25:52 2016 Cédric Thomas
<<<<<<< HEAD
** Last update Tue Nov  1 23:56:25 2016 Arthur Knoepflin
=======
** Last update Mon Oct 31 21:23:50 2016 Cédric Thomas
>>>>>>> 7fecd17606b7771981a29d5fa21032d8b1c262f0
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

t_ci	stru_dup(t_ci *ci)
{
  t_ci	duped;

  duped.n = my_strdup(ci->n);
  duped.s = ci->s;
  duped.l = ci->l;
  return (duped);
}

int	t_ci_cmp(t_ci *ci1, t_ci *ci2)
{
  if (ci1->l == ci2->l && my_strcmp(ci1->n, ci2->n) == 0)
    return (0);
  else if (ci1->l == ci2->l && my_strcmp(ci1->n, ci2->n) < 0
      || ci1->l < ci2->l)
    return (-1);
  else if (ci1->l == ci2->l && my_strcmp(ci1->n, ci2->n) > 0
      || ci1->l > ci2->l)
    return (1);  
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
    return (NULL);
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

t_ci	stru_dup(t_ci *stru)
{
  t_ci	duped;

  duped.n = my_strdup(stru->n);
  duped.s = stru->s;
  duped.l = my_strlen(stru->n);
  return (duped);
}
  
