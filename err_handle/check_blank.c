/*
** check_blank.c for blank check in /home/cedric/delivery/module_bistro
**
** Made by Cédric Thomas
** Login   <cedric.thomas@epitech.net>
**
** Started on  Thu Nov  3 20:52:12 2016 Cédric Thomas
** Last update Sun Nov  6 19:49:19 2016 Cebrail Aktas
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	valide(char c)
{
  if (c != '*' && c != '/' && c != '%')
      if (c != '+' && c != '-')
	return (0);
  return (1);
}

void	check_blank(char *str, char *base)
{
  int	i;
  int	bool;

  i = 0;
  bool = 0;
  while (str[i] != 0)
    {
      if (i > 0 && (is_number(str[i - 1], base)
		    || str[i - 1] == ')') && str[i] == ' ')
	bool = 1;
      else if (i > 0 && is_number(str[i], base) && bool == 1)
	{
	  my_puterror(SYNTAX_ERROR_MSG);
	  exit(EXIT_OPS);
	}
      else if (valide(str[i]))
	bool = 0;
      i += 1;
    }
}
