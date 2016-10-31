/*
** change_sign.c for change_sign in /home/cedric/CPool_evalexpr
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Fri Oct 28 10:46:39 2016 Cédric Thomas
** Last update Fri Oct 28 13:13:09 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

int	get_sign(char *src)
{
  int	i;
  int	add;

  i = 0;
  add = 0;
  while (src[i] != '\0')
    {
      if (i > 0 && src[i] == '(' && src[i - 1] == '-')
	add += 2;
      i += 1;
    }
  return (add);
}

char	*change_sign(char *src)
{
  char	*dest;
  int	i;
  int	j;

  dest = malloc(sizeof(char) * (my_strlen(src) + 1 + get_sign(src)));
  i = 0;
  j = 0;
  while (src[i] != '\0')
    {
      if ((i + 1) < my_strlen(src) && src[i] == '-' && src[i + 1] == '(')
	{
	  dest[j] = src[i];
	  dest[j + 1] = '1';
	  dest[j + 2] = '*';
	  j += 2;
	}
      else
	dest[j] = src[i];
      j += 1;
      i += 1;
    }
  dest[j] = '\0';
  free(src);
  return (dest);
}
