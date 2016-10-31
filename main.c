/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Mon Oct 31 11:21:24 2016 Cédric Thomas
*/

#include "my.h"
#include "bistro.h"

int	main(int ac, char **av)
{
  t_ci	nb;
  t_ci	nb1;
  t_ci	nb2;

  if (ac != 4)
    return (84);
  char_to_stru(&nb1, av[1]);
  char_to_stru(&nb2, av[3]);
  if (my_strcmp("+", av[2]) == 0)
    infinadd(nb1, nb2, &nb);
  else if (my_strcmp("-", av[2]) == 0)
    infinsub(nb1, nb2, &nb);
  else
    return (0);
  if (nb.s == 1)
    my_putstr("-");
  my_putstr(nb.n);
  my_putchar('\n');
  return (0);
}
