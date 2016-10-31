/*
** main.c for mul_inf in /home/arthur/c/mul_inf
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Fri Oct 28 15:24:48 2016 Arthur Knoepflin
** Last update Mon Oct 31 12:33:10 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "mul_inf.h"
#include "my.h"

int	stl(char *str)
{
  return (my_strlen(str));
}

t_nbr	clear_str(t_nbr *str)
{
  t_nbr	ret;
  int	len;
  int	start;
  int	i;

  start = 0;
  len = 0;
  while (str->nbr[start] == '0' && str->nbr[start + 1] != '\0')
    start += 1;
  while (str->nbr[start + len])
    len += 1;
  ret.nbr = malloc(sizeof(char) * (len + 1));
  ret.nbr[len] = '\0';
  i = 0;
  while (i < len)
    {
      ret.nbr[i] = str->nbr[start + i];
      i += 1;
    }
  return (ret);
}

void	calc_neg(t_nbr *nb1, t_nbr *nb2, t_nbr *ret)
{
  if (nb1->neg == 1 || nb2->neg == 1)
    ret->neg = 1;
  if (nb1->neg == 1 && nb2->neg == 1)
    ret->neg = 0;
}

t_nbr	mul_inf(t_nbr *nb1, t_nbr *nb2)
{
  int	i;
  int	j;
  int	tmp;
  t_nbr	ret;

  i = my_strlen(nb1->nbr) - 1;
  j = my_strlen(nb2->nbr) - 1;
  calc_neg(nb1, nb2, &ret);
  ret.nbr = malloc(sizeof(char) * (stl(nb1->nbr) + stl(nb2->nbr) + 1));
  my_memset(ret.nbr, '0', stl(nb1->nbr) + stl(nb2->nbr));
  ret.nbr[stl(nb1->nbr) + stl(nb2->nbr)] = '\0';
  while (i >= 0)
    {
      j = my_strlen(nb2->nbr) - 1;
      while (j >= 0)
	{
	  tmp = (nb1->nbr[i] - '0') * (nb2->nbr[j] - '0');
	  ret.nbr[i + j] += ((ret.nbr[i + j + 1] + tmp - '0') / 10);
	  ret.nbr[i + j + 1] = ((ret.nbr[i + j + 1] + tmp - '0') % 10) + '0';
	  j -= 1;
	}
      i -= 1;
    }
  return (ret);
}

int	get_nl(char *nb)
{
  int	i;

  i = 0;
  while (nb[i] == '0' && nb[i + 1] != '\0')
    i += 1;
  return (i);
}
