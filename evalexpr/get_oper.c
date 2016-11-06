/*
** get_oper.c for get_oper in /home/arthur/c/CPool_evalexpr/
**
** Made by Arthur Knoepflin
** Login   <arthur.knoepflin@epitech.net>
**
** Started on  Mon Oct 31 10:30:26 2016 Arthur Knoepflin
** Last update Sun Nov  6 19:48:03 2016 Cebrail Aktas
*/

int	is_number(char c, char *num_list)
{
  int	i;

  i = 0;
  while (num_list[i])
    {
      if (c == num_list[i])
	return (1);
      i += 1;
    }
  return (0);
}
