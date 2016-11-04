/*
** check_parent.c for check_parent in /home/arthur/c/bistro eval expr
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Nov  3 20:53:59 2016 Arthur Knoepflin
** Last update Fri Nov  4 14:38:34 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

void	check_parent(char *str)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '(')
	count += 1;
      if (str[i] == ')')
	count -= 1;
      if (count < 0)
	stop();
      i += 1;
    }
  if (count != 0)
    stop();
}

void	stop()
{
  my_puterror(SYNTAX_ERROR_MSG);
  exit(EXIT_OPS);
}

void	check_syntax(char *str, char *base)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_number(str[i], base))
	{
	  while (is_number(str[i], base))
	    i += 1;
	  if (i != my_strlen(str) && !search_c("+-*/%)\n", str[i]))
	    stop();
	}
      else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
	if (!(is_number(str[i + 1], base)) && str[i + 1] != '(')
	  stop();
      if (search_c("+-*/%", str[i]))
	if (i == my_strlen(str) - 1 || str[i + 1] == ')')
	  stop();
      if (str[i] == '(' && search_c(")*/%", str[i + 1]))
	stop();
      if (str[i] == ')' && str[i + 1] == '(')
	stop();
      if (i <= my_strlen(str) - 1)
	i += 1;
    }
}
