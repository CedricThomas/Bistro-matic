/*
** module_bistro.c for bistro in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Mon Oct 24 18:25:52 2016 Cédric Thomas
** Last update Mon Oct 31 13:21:32 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

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
