/*
** main.c for mul_inf in /home/arthur/c/mul_inf
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Fri Oct 28 15:24:48 2016 Arthur Knoepflin
** Last update Wed Nov  2 22:24:31 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "bistro.h"
#include "my.h"

int	stl(char *str)
{
  return (my_strlen(str));
}

void	clear_str(t_ci *str)
{
  char	*ret;
  int	len;
  int	start;
  int	i;

  start = 0;
  len = 0;
  while (str->n[start] == '0' && str->n[start + 1] != '\0')
    start += 1;
  while (str->n[start + len])
    len += 1;
  if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
    {
      str->n = NULL;
      return ;
    }
  ret[len] = '\0';
  i = 0;
  while (i < len)
    {
      ret[i] = str->n[start + i];
      i += 1;
    }
  str->n = ret;
}

void	calc_neg(t_ci *nb1, t_ci *nb2, t_ci *ret)
{
  if (nb1->s == 1 || nb2->s == 1)
    ret->s = 1;
  if ((nb1->s == 1 && nb2->s == 1) ||
      (nb1->s == 0 && nb2->s == 0))
    ret->s = 0;
}

char	*infinmul_calc(t_ci *nb1, t_ci *nb2)
{
  int	i;
  int	j;
  int	tmp;
  char	*ret;

  i = my_strlen(nb1->n) - 1;
  j = my_strlen(nb2->n) - 1;
  if ((ret = malloc(sizeof(char) * (nb1->l + nb2->l + 1))) == NULL)
    return (ret);
  my_memset(ret, '0', nb1->l + nb2->l);
  ret[nb1->l + nb2->l] = '\0';
  while (i >= 0)
    {
      j = my_strlen(nb2->n) - 1;
      while (j >= 0)
	{
	  tmp = (nb1->n[i] - '0') * (nb2->n[j] - '0');
	  ret[i + j] += ((ret[i + j + 1] + tmp - '0') / 10);
	  ret[i + j + 1] = ((ret[i + j + 1] + tmp - '0') % 10) + '0';
	  j -= 1;
	}
      i -= 1;
    }
  return (ret);
}

t_ci	infinmul(t_ci nb1, t_ci nb2)
{
  t_ci	ret;
  char	*calc;

  calc = infinmul_calc(&nb1, &nb2);
  ret.n = calc;
  calc_neg(&nb1, &nb2, &ret);
  ret.l = my_strlen(ret.n);
  clear_str(&ret);
  free(calc);
  return (ret);
}
