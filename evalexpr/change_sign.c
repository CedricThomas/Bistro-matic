/*
** change_sign.c for change_sign in /home/cedric/CPool_evalexpr
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Fri Oct 28 10:46:39 2016 Cédric Thomas
** Last update Sun Nov  6 19:47:29 2016 Cebrail Aktas
*/

#include <stdlib.h>
#include "my.h"
#include "bistro.h"

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

  if ((dest = malloc(sizeof(char) * (stl(src) + 1 + get_sign(src)))) == NULL)
    exit(EXIT_MALLOC);
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

char	*get_oper_norm()
{
  char	*oper;

  if ((oper = malloc(sizeof(char) * (8))) == NULL)
    exit(EXIT_MALLOC);
  oper[0] = '(';
  oper[1] = ')';
  oper[2] = '+';
  oper[3] = '-';
  oper[4] = '*';
  oper[5] = '/';
  oper[6] = '%';
  oper[7] = '\0';
  return (oper);
}

int	is_opera(char c, char *op)
{
  int	i;

  i = 0;
  while (op[i])
    {
      if (op[i] == c)
	return (i);
      i += 1;
    }
  return (-1);
}

char	*change_op(char *str, char *op)
{
  int	i;
  char	*oper;
  char	*ret;

  i = 0;
  oper = get_oper_norm();
  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_MALLOC);
  ret[my_strlen(str)] = '\0';
  while (str[i])
    {
      if (is_opera(str[i], op) >= 0)
	ret[i] = oper[is_opera(str[i], op)];
      else
	ret[i] = str[i];
      i += 1;
    }
  return (ret);
}
