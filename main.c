/*
** main.c for main.c in /home/cedric/delivery/ex
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Sat Oct 22 10:31:05 2016 Cédric Thomas
** Last update Thu Nov  3 20:37:12 2016 Arthur Knoepflin
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

static void	print_help()
{
  my_putstr("USAGE\n");
  my_putstr("\t./calc base operators size_read\n\n");
  my_putstr("DESCRIPTION\n\tbase\t   all the symbols of the base\n");
  my_putstr("\toperators  the symbols ");
  my_putstr("for the parentheses and the 5 operators\n");
  my_putstr("\tsize_read  number of characters to be read\n");
}

int	main(int ac, char **av)
{
  char		*expr;
  char    *rst;
  unsigned int	size;

  if (ac == 2 && my_strcmp(av[1], "-h") == 0)
    {
      print_help();
      return (EXIT_SUCCESS);
    }
  if (ac != 4)
    {
      my_putstr("Usage: ");
      my_putstr(av[0]);
      my_putstr(" base ops \"()+-*/%\" exp_len\n");
      return (EXIT_USAGE);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  rst = eval_expr(expr, av[2], av[1]);
  my_putstr(rst);
  return (EXIT_SUCCESS);
}
