/*
** my_memset.c for my_memset in /home/arthur/delivery/CPool_infinadd
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 24 13:38:08 2016 Arthur Knoepflin
** Last update Mon Oct 24 13:39:36 2016 Arthur Knoepflin
*/

void	my_memset(char *str, int c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i += 1;
    }
}
