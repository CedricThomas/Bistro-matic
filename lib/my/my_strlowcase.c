/*
** my_strlowcase.c for my_strlowcase.c in /home/cedric/delivery/CPool_Day06
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Mon Oct 10 15:51:30 2016 Cédric Thomas
** Last update Mon Oct 10 16:13:36 2016 Cédric Thomas
*/

#include <unistd.h>

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if (str[i] <= 'Z' && str[i] >= 'A')
	str[i] += 32;
      i += 1;
    }
  return (str);
}
