/*
** bistro.h for Bistromathique in /home/cedric/delivery/CPool_infinadd
**
** Made by Cédric Thomas
** Login   <cedric@epitech.net>
**
** Started on  Mon Oct 24 10:18:20 2016 Cédric Thomas
<<<<<<< HEAD
** Last update Mon Oct 31 13:45:01 2016 Arthur Knoepflin
=======
** Last update Mon Oct 31 12:04:06 2016 Cebrail Aktas
>>>>>>> 601521785ae3bf39eea882e5b6ccdf3c93d563e1
*/

#ifndef BISTRO_H_
# define BISTRO_H_

# define ABS(x) ((x) < 0 ? -(x) : (x))

struct		s_char_int
{
  int		s;
  int		l;
  char		*n;
};
typedef struct	s_char_int	t_ci;

int	transfert(t_ci *ci, char *nb);
int	t_ci_cmp(t_ci *nb1, t_ci *nb2);
t_ci	infinadd(t_ci nb1, t_ci nb2);
t_ci	infinsub(t_ci nb1, t_ci nb2);

t_ci	infinmul(t_ci *, t_ci *);

/*
** error.c
*/
void	my_puterror(char *);
int	check_parenthesis(char *);
int	check_errors(char *);

#endif /* !BISTRO_H_ */
