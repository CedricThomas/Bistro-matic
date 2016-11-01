/*
** do-op.c for do-op in /home/arthur/delivery/CPool_EvalExpr
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 25 22:43:58 2016 Arthur Knoepflin
** Last update Wed Nov  2 00:03:47 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "my.h"
#include "bistro.h"

int	get_oper(char *str)
{
  if (str)
    {
      if (str[0] == '+')
	return (0);
      if (str[0] == '-')
	return (1);
      if (str[0] == '*')
	return (2);
      if (str[0] == '/')
	return (3);
      if (str[0] == '%')
	return (4);
      return (5);
    }
  return (6);
}

int	size_int(int nb)
{
  int   i;

  i = 0;
  if (nb == 0)
    return (1);
  while (nb != 0)
    {
      nb = nb / 10;
      i += 1;
    }
  return (i);
}

char	*toc_alloc(int nb)
{
  char  *ret;
  if (nb < 0)
    {
      ret = malloc(sizeof(char) * (size_int(nb) + 2));
      ret[0] = '-';
      nb *= (-1);
    }
  else
    {
      ret = malloc(sizeof(char) * (size_int(nb) + 1));
    }
  return (ret);
}

char	*int_toc(int nb)
{
  int   i[2];
  char  *ret;

  i[0] = 1;
  i[1] = size_int(nb);
  ret = toc_alloc(nb);
  if (nb < 0)
    {
      nb *= (-1);
      ret[size_int(nb) + 1] = '\0';
    }
  else
    {
      i[1] -= 1;
      ret[size_int(nb)] = '\0';
    }
  while (i[0] <= size_int(nb))
    {
      ret[i[1]] = (nb / my_power_rec(10, i[0] - 1) % 10) + 48;
      i[1] -= 1;
      i[0] += 1;
    }
  if (nb == 0)
    ret[0] = '0';
  return (ret);
}

char	*do_op(char *a, char *b, char *char_oper)
{
  t_ci	a_stru;
  t_ci	b_stru;
  t_ci	rst_stru;
  t_ci	(*calc_op[5])(t_ci, t_ci);

  char_to_stru(&a_stru, a);
  char_to_stru(&b_stru, b);
  calc_op[0] = &infinadd;
  calc_op[1] = &infinsub;
  calc_op[2] = &infinmul;
  calc_op[3] = &infindiv;
  calc_op[4] = &infinmod;
  rst_stru = calc_op[get_oper(char_oper)](a_stru, b_stru);
  return (stru_to_char(&rst_stru));
}
