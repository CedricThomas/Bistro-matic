/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Fri Oct 28 13:14:54 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

int	eval_expr(char *str)
{
  char	*epured;
  char	**rpn;

  epured = change_sign(my_epurstr(str));
  rpn = in_to_rpn(str_to_stack(epured));
  free(epured);
  return (calc(rpn));
}

int	main(int ac, char **av)
{
  char	*str;

  if (ac == 2)
    {
      my_put_nbr(eval_expr(av[1]));
      my_putchar('\n');
      return (0);
    }
  return (84);
}
