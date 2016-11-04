/*
** check_base.c for CPool_bistro-matic in /home/kaynabx/delivery/CPool_bistro-matic/err_handle/
**
** Made by Cebrail Aktas
** Login   <cebrail.aktas@epitech.eu>
**
** Started on  Wed Nov  2 09:55:50 2016 Cebrail Aktas
** Last update Fri Nov  4 15:11:23 2016 Arthur Knoepflin
*/
#include <unistd.h>
#include "bistro.h"
#include "my.h"

int	check_spaces(char *base)
{
  int	i;

  i = -1;
  if (!(base))
    return (EXIT_USAGE);
  while (base[++i])
    {
      if (base[i] <= 32)
	return (EXIT_USAGE);
    }
  return (0);
}

int	check_base_ops(char *base, char *ops)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(base) || !(ops))
    return (EXIT_USAGE);
  while (ops[j])
    {
      while (ops[j] != base[i] && (base[i]))
	i++;
      if (ops[j] == base[i])
	{
	  my_puterror(SYNTAX_ERROR_MSG);
	  return (EXIT_USAGE);
	}
      if (base[i] == '\0')
	{
	  j++;
	  i = 0;
	}
    }
  return (0);
}

int	check_ops_in_calc(char *calc, char *ops)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = 0;
  if (!(calc) || !(ops))
    return (EXIT_USAGE);
  while (calc[++i])
    {
      while (ops[j] != calc[i] && (calc[i]))
	i++;
      if (ops[j] == calc[i] && (calc[i]))
	k++;
      if (calc[i] == '\0' && ops[j++] != '\0')
	i = 0;
    }
  if (k == 0)
    {
      my_puterror(SYNTAX_ERROR_MSG);
      return (EXIT_USAGE);
    }
  return (0);
}
