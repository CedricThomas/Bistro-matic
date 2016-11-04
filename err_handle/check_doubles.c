/*
** check_doubles.c for CPool_bistro-matic in /home/kaynabx/delivery/CPool_bistro-matic/err_handle/
**
** Made by Cebrail Aktas
** Login   <cebrail.aktas@epitech.eu>
**
** Started on  Thu Nov  3 16:56:20 2016 Cebrail Aktas
** Last update Fri Nov  4 13:30:10 2016 Arthur Knoepflin
*/
#include <unistd.h>
#include "bistro.h"
#include "my.h"

int	check_double_ops(char *ops)
{
  int	i;
  int	k;

  i = -1;
  if (!(ops))
    return (EXIT_USAGE);
  while (++i < my_strlen(ops))
    {
      k = i + 1;
      while (k < my_strlen(ops))
	{
	  if (ops[k] == ops[i])
	    {
	      my_puterror(SYNTAX_ERROR_MSG);
	      return (EXIT_USAGE);
	    }
	  k++;
	}
    }
  return (0);
}

int	check_double_base(char *base)
{
  int	i;
  int	k;

  i = -1;
  if (!(base))
    return (EXIT_USAGE);
  while (++i < my_strlen(base))
    {
      k = i + 1;
      while (k < my_strlen(base))
	{
	  if (base[k] == base[i])
	    {
	      my_puterror(SYNTAX_ERROR_MSG);
	      return (EXIT_USAGE);
	    }
	  k++;
	}
    }
  return (0);
}
