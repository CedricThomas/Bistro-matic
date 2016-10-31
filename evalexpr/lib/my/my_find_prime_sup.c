/*
** my_find_prime_sup.c for my_find_prime_sup.c in /home/arthur/delivery/CPool_Day05
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Oct  7 17:18:52 2016 Arthur Knoepflin
** Last update Fri Oct  7 21:53:46 2016 Arthur Knoepflin
*/

int	my_find_prime_sup(int nb)
{
  if (!my_is_prime(nb))
    {
      nb = my_find_prime_sup(nb + 1);
    }
  return (nb);
}
