/*
** error.c for CPool_bicalco-matic in /home/kaynabx/delivery/CPool_bicalco-matic/err_handle/
**
** Made by Cebrail Aktas
** Login   <cebrail.aktas@epitech.eu>
**
** Started on  Mon Oct 31 11:50:47 2016 Cebrail Aktas
** Last update Sun Nov  6 22:05:10 2016 Cédric Thomas
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

int	check_errors(char *calc, char *base, char *ops)
{
  int	err_count;

  err_count = 0;
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
