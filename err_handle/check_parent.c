/*
** check_parent.c for check_parent in /home/arthur/c/bistro eval expr
**
** Made by Arthur Knoepflin
** Login   <arthur.knoepflin@epitech.net>
**
** Started on  Thu Nov  3 20:53:59 2016 Arthur Knoepflin
** Last update Sun Nov  6 19:49:31 2016 Cebrail Aktas
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

void	treat_op(char *str, int *i)
{
  if (search_c("*/%", str[*i]))
    if (*i == my_strlen(str) - 1 || str[*i + 1] == ')')
      stop();
  if (search_c("+-", str[*i]))
    {
      while (str[*i] && search_c("+-", str[*i]))
	{
	  *i += 1;
	  if (*i == my_strlen(str) || search_c("*/%)\n", str[*i]))
	    stop();
	}
    }
  if (str[*i] == '(' && search_c(")*/%", str[*i + 1]))
    stop();
  if (str[*i] == ')' && str[*i + 1] == '(')
    stop();
}

void	check_syntax(char *str, char *base)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (is_number(str[i], base))
	{
	  nb += 1;
	  while (is_number(str[i], base))
	    i += 1;
	  if (i != my_strlen(str) && !search_c("+-*/%)\n", str[i]))
	    stop();
	}
      else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
	if (!(is_number(str[i + 1], base)) && str[i + 1] != '(')
	  stop();
      treat_op(str, &i);
      if (i <= my_strlen(str) - 1)
	i += 1;
    }
  if (nb == 0)
    stop();
}
