/*
** main.c for main.c in /home/cedric/delivery/ex
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Sun Nov  6 23:26:36 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

static int	check(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i])
    {
      if (search_c(str2, str1[i]))
	return (1);
      i += 1;
    }
  return (0);
}

char	*eval_expr(char *str, char *op, char *b)
{
  char	*epured;
  char	**rpn;
  char	*result;

  if (check(b, "()+-*/%"))
    {
      my_puterror(ERROR_MSG);
      exit(EXIT_USAGE);
    }
  check_expr(b, op, epured);
  epured = change_op(str, op);
  check_blank(epured, b);
  check_parent(epured);
  epured = change_sign(opsup(my_epurstr(epured)));
  epured = opsup(epured);
  check_syntax(epured, b);
  rpn = in_to_rpn(str_to_stack(epured, b), b);
  free(epured);
  result = calc(rpn, b);
  if (result[0] == '-')
    result[0] = op[3];
  return (result);
}
