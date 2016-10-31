/*
** convert.c for convert in /home/arthur/c/CPool_evalexpr/
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Oct 31 09:34:47 2016 Arthur Knoepflin
** Last update Mon Oct 31 10:26:34 2016 Cédric Thomas
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	char_to_stru(t_ci *ci, char *nb)
{
  int	i;

  i = 0;
  if (nb[0] == '-')
    {
      (*ci).n = nb + 1 + get_nl(nb + 1);
      (*ci).s = 1;
      (*ci).l = my_strlen((*ci).n);
    }
  else
    {
      (*ci).n = nb + get_nl(nb);
      (*ci).s = 0;
      (*ci).l = my_strlen((*ci).n);
    }
  while ((*ci).n[i] != '\0')
    {
      if ((*ci).n[i] < '0' || (*ci).n[i] > '9')
	return (1);
      i += 1;
    }
  return (0);
}

char	*stru_to_char_malloc(t_ci *ci)
{
  char	*nbr;

  if ((*ci).s == 1)
    {
      if ((nbr = malloc(sizeof(char) * ((*ci).l + 2))) == NULL)
	return (NULL);
      nbr[0] = '-';
      nbr[(*ci).l + 1] = '\0';
    }
  else
    {
      if ((nbr = malloc(sizeof(char) * ((*ci).l + 1))) == NULL)
	return (NULL);
      nbr[(*ci).l] = '\0';
    }
  return (nbr);
}

char	*stru_to_char(t_ci *ci)
{
  int	i;
  int	j;
  char *nbr;

  if ((nbr = stru_to_char_malloc(ci)) == NULL)
    return (NULL);
  j = 0;
  if ((*ci).s == 1)
    i = 1;
  else
    i = 0;
  while (j < (*ci).l)
    {
      nbr[i] = (*ci).n[j];
      i += 1;
      j += 1;
    }
  return (nbr);
}
