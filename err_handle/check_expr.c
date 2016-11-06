/*
** check_expr.c for check epr in /home/cedric/delivery/module_bistro
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Thu Nov  3 22:04:13 2016 Cédric Thomas
** Last update Sun Nov  6 19:49:27 2016 Cebrail Aktas
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	search_c(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	return (1);
      i += 1;
    }
  return (0);
}

static int	check_same(char *stra, char *strb)
{
  int		i;
  int		j;

  i = 0;
  while (stra[i] != 0)
    {
      j = 0;
      while (strb[j] != 0)
	{
	  if (stra[i] == strb[j])
	    return (1);
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

void	check_expr(char *base, char *ope, char *expr)
{
  int	i;

  i = 0;
  while (expr[i] != 0)
    {
      if (search_c(base, expr[i]) == 0 &&
	  search_c(ope, expr[i]) == 0 &&
	  search_c(" \n", expr[i]) == 0)
	{
	  my_puterror(SYNTAX_ERROR_MSG);
	  exit(EXIT_OPS);
	}
      i += 1;
    }
  if (check_same(" ", base) || check_same(" ", ope) || check_same(ope, base))
    {
      my_puterror(SYNTAX_ERROR_MSG);
      exit(EXIT_OPS);
    }
}
