/*
** evalexpr for evalexpr.c in /home/cedric/delivery/ex
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Tue Nov  1 22:35:30 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

/*
** retour calc rpn
*/

char	*eval_expr(t_list list, unsigned int size)
{
  char	*epured;
  char	**rpn;
  int	i;

  i = 0;
  epured = change_sign(my_epurstr(list));
  list.e = epured;
  my_putchar('\n');
  rpn = in_to_rpn(str_to_stack(list), list);
  my_show_wordtab(rpn);
  while (rpn[i])
    {
      free(rpn[i]);
      i += 1;
    }
  free(rpn);
  return (calc(rpn, list));
  return (list.e);
}
