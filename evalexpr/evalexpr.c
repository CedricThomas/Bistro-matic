/*
** main.c for main.c in /home/cedric/delivery/ex
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Thu Nov  3 18:56:17 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

char	*eval_expr(char *str, char *op, char *b)
{
  char	*epured;
  char	*epured_2;
  char	**rpn;

  epured_2 = change_sign(opsup(my_epurstr(str)));
  epured = opsup(epured_2);
  free(epured_2);
  epured = change_op(epured, op);
  rpn = in_to_rpn(str_to_stack(epured, b), b);
  free(epured);
  return (calc(rpn, b));
}
