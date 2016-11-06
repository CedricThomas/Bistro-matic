/*
** my_putstr.c for my_putstr.c in /home/cedric/delivery/CPool_Day04
** 
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
** 
** Started on  Thu Oct  6 11:13:52 2016 Cédric Thomas
** Last update Tue Oct 11 17:12:17 2016 Cédric Thomas
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return ;
}
