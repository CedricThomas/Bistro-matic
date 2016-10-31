/*
** my.h for my in /home/arthur/delivery/CPool_Day09
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Oct 13 11:20:08 2016 Arthur Knoepflin
** Last update Thu Oct 27 22:41:11 2016 Arthur Knoepflin
*/

#ifndef MY_H_
# define MY_H_

/*
** Lib
*/

void		my_putchar(char c);
char		**my_str_to_wordtab(char *str);
void		my_memset(char *, int, int);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_getnbr_base(char *str);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int p);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
char		*my_strdup(char *src);
static void	first_row(int c);
static void	second_row(int l, char *str, int size);
static void	third_row(int l, char *str, int size);
static int	nb_less(char *str, int index);
static int	my_getnbr_core(char *str, int count, int block, int neg);
static int	my_putnbr_base_length(char *base);
static int	my_putnbr_base(int nbr, char *base);
static int	my_strstr_strlen(char *str);
static int	my_showstr(char *str);
static int	my_rev_strlen(char *str);

#endif /* !MY_H_ */
