/*
** convert.c for convert in /home/arthur/c/CPool_evalexpr/
**
** Made by Arthur Knoepflin
** Login   <arthur.knoepflin@epitech.net>
**
** Started on  Mon Oct 31 09:34:47 2016 Arthur Knoepflin
** Last update Sun Nov  6 19:47:49 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "bistro.h"
#include "my.h"

static char	*my_strndup(char *src, int index)
{
  char		*dest;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (src == NULL || my_strlen(src) < index)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1 - index))) == NULL)
    exit(EXIT_MALLOC);
  while (src[i] != '\0')
    {
      if (i > index)
	{
	  dest[j] = src[i];
	  j += 1;
	}
      i += 1;
    }
  dest[j] = '\0';
  return (dest);
}

int	char_to_stru(t_ci *ci, char *nb)
{
  int	i;

  i = 0;
  if (nb[0] == '-')
    {
      (*ci).n = my_strndup(nb, get_nl(nb + 1));
      (*ci).s = 1;
      (*ci).l = my_strlen((*ci).n);
    }
  else
    {
      (*ci).n = my_strndup(nb, get_nl(nb) - 1);
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
