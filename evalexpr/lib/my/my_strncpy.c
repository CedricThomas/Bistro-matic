/*
** my_strncpy.c for my_strncpy in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 09:49:08 2016 Arthur Knoepflin
** Last update Mon Oct 10 14:28:34 2016 Arthur Knoepflin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (i < n)
    dest[i] = '\0';
  return (dest);
}
