/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Fri Nov  4 14:59:23 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

static int	op_get_nbop(char *str, int i)
{
  int		size;

  size = 0;
  while (str[i + size] == '-' || str[i + size] == '+')
    size += 1;
  return (size);
}

static int	op_get_parity(char *str, int i)
{
  int		size;
  int		parity;

  size = 0;
  parity = 0;
  while (str[i + size] == '-' || str[i + size] == '+')
    {
      if (str[i + size] == '-')
	parity += 1;
      size += 1;
    }
  size += 1;
  return (parity % 2);
}

static int	op_get_size(char *str)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (str[i] != 0)
    {
      if (str[i] == '+' || str[i] == '-')
	{
	  while ((str[i] == '+' || str[i] == '-') && str[i + 1] != 0)
	    i += 1;
	  size += 1;
	}
      size += 1;
      i += 1;
    }
  return (size);
}

static char	*del_plus(char *str, int i, int j, int size)
{
  char		*epured;

  while (str[i] != 0)
    {
      if (str[i] == '(' && str[i + 1] == '+' || i == 0 && str[i] == '+')
	size -= 1;
      i += 1;
    }
  i = 0;
  j = 0;
  if ((epured = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(EXIT_MALLOC);
  my_memset(epured, '\0', size + 1);
  while (str[i] != 0)
    {
      if (!(i > 0 && str[i] == '+' &&
	    str[i - 1] == '(' || i == 0 && str[i] == '+'))
	{
	  epured[j] = str[i];
	  j += 1;
	}
      i += 1;
    }
  free(str);
  return (epured);
}

char	*opsup(char *str)
{
  char	*epured;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((epured = malloc(sizeof(char) * (op_get_size(str) + 1))) == NULL)
    exit(EXIT_MALLOC);
  epured[op_get_size(str)] = '\0';
  while (str[i] != 0)
    {
      if (str[i] == '+' || str[i] == '-')
	{
	  if (op_get_parity(str, i) == 1)
	    epured[j] = '-';
	  else
	    epured[j] = '+';
	  i += op_get_nbop(str, i) - 1;
	}
      else
	  epured[j] = str[i];
      j += 1;
      i += 1;
    }
  epured = del_plus(epured, 0, 0, my_strlen(epured));
  return (epured);
}
