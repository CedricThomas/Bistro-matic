/*
** main.c for main.c in /home/cedric/delivery/ex
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Tue Nov  1 22:38:56 2016 Arthur Knoepflin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bistro.h"

static void	check_base(char *b)
{
  if (my_strlen(b) < 2)
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit(EXIT_BASE);
    }
}

static char	*get_expr(unsigned int size)
{
  char		*expr;

  if (size <= 0)
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit (EXIT_SIZE_NEG);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      my_putstr(ERROR_MSG);
      exit(EXIT_MALLOC);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr(ERROR_MSG);
      exit(EXIT_READ);
    }
  expr[size] = '\0';
  return (expr);
}

static void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr(SYNTAX_ERROR_MSG);
      exit(EXIT_OPS);
    }
}

int	main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;
  t_list	list;

  if (ac != 4)
    {
      my_putstr("Usage: ");
      my_putstr(av[0]);
      my_putstr(" base ops \"()+_*/%\" exp_len\n");
      return (EXIT_USAGE);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  list.e = get_expr(size);
  list.b = av[1];
  list.o = av[2];
  expr = eval_expr(list, size);
  free(list.e);
  return (EXIT_SUCCESS);
}
