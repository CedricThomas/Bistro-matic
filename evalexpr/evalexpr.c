/*
** main.c for main.c in /home/cedric/delivery/ex
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Fri Nov  4 14:54:01 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

char	*eval_expr(char *str, char *op, char *b)
{
  char	*epured;
  char	*epured_2;
  char	**rpn;

  epured = change_op(str, op);
  check_blank(epured, b);
  check_parent(str);
  check_expr(b, op, str);
  epured_2 = change_sign(opsup(my_epurstr(epured)));
  epured = opsup(epured_2);
  check_syntax(epured_2, b);
  free(epured_2);
  rpn = in_to_rpn(str_to_stack(epured, b), b);
  free(epured);
  return (calc(rpn, b));
}
