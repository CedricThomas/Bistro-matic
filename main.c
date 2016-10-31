/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Mon Oct 31 13:56:13 2016 Arthur Knoepflin
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
    nb = infinadd(nb1, nb2);
  else if (my_strcmp("-", av[2]) == 0)
    nb = infinsub(nb1, nb2);
  else if (my_strcmp("*", av[2]) == 0)
    nb = infinmul(&nb1, &nb2);
  else
    return (0);
  if (nb.s == 1)
    my_putstr("-");
  my_putstr(nb.n);
  my_putchar('\n');
  return (0);
}
