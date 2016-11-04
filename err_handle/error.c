/*
** error.c for CPool_bicalco-matic in /home/kaynabx/delivery/CPool_bicalco-matic/err_handle/
**
** Made by Cebrail Aktas
** Login   <cebrail.aktas@epitech.eu>
**
** Started on  Mon Oct 31 11:50:47 2016 Cebrail Aktas
** Last update Fri Nov  4 14:41:56 2016 Arthur Knoepflin
*/
#include <unistd.h>
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

void	my_puterror(char *calc)
{
  int	i;

  i = 0;
  while (calc[i])
    {
      write(2, &calc[i], 1);
      i++;
    }
}

int	my_is_op(char c)
{
  if (c != '+' || c != '/' || c != '-' || c != '*')
    return (EXIT_USAGE);
  return (0);
}

int	check_parenthesis(char *calc)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = 0;
  if (!(calc))
    return (EXIT_USAGE);
  while (calc[++i])
    {
      if (calc[i] == '(')
	j++;
      else if (calc[i] == ')')
	k++;
    }
  if (j != k)
    {
      my_puterror(SYNTAX_ERROR_MSG);
      return (EXIT_USAGE);
    }
  return (0);
}

int	check_op(char *calc)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = 0;
  if (!(calc))
    return (EXIT_USAGE);
  while (calc[++i])
    {
      if (my_is_op(calc[i + 1]) == 0 && my_is_op(calc[i]) == 0)
	{
	 my_puterror(SYNTAX_ERROR_MSG);
	exit(EXIT_USAGE);
	}
    }
  return (0);
}

int	check_errors(char *calc, char *base, char *ops)
{
  int	err_count;

  err_count = 0;
  err_count = check_op(ops);
  err_count += check_parenthesis(calc);
  err_count += check_spaces(base);
  err_count += check_base_ops(base, ops);
  err_count += check_double_base(base);
  err_count += check_double_ops(ops);
  if (err_count != 0)
    {
      exit(EXIT_USAGE);
    }
  return (0);
}
