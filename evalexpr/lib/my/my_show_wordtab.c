/*
** my_show_wordtab.c for my_show_wordtab in /home/arthur/delivery/CPool_Day08/task03/
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Wed Oct 12 11:23:35 2016 Arthur Knoepflin
** Last update Wed Oct 12 15:15:36 2016 Arthur Knoepflin
*/
#include <stdlib.h>

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i += 1;
    }
  return (i);
}
