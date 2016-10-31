/*
** error.c for CPool_bistro-matic in /home/kaynabx/delivery/CPool_bistro-matic/err_handle/
**
** Made by Cebrail Aktas
** Login   <cebrail.aktas@epitech.eu>
**
** Started on  Mon Oct 31 11:50:47 2016 Cebrail Aktas
** Last update Mon Oct 31 15:09:00 2016 Cebrail Aktas
*/
void	my_puterror(char *str)
{
  write(2, &str, my_strlen(str));
}

int	my_is_op(char c)
{
  if (c != '+' || c != '/' || c != '-' || c != '*')
    return (1);
  return (0);
}

int	check_parenthesis(char *str)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = 0;
  if (!(str))
    return (-1);
  while (str[++i])
    {
      if (str[i] == '(')
	j++;
      else if (str[i] == ')')
	k++;
    }
  if (j != k)
    {
      my_puterror("Syntaxe error. Please check parenthesis.");
      return (-1);
    }
  return (0);
}

int	check_op(char *str)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  k = 0;
  if (!(str))
    return (1);
  while (str[++i])
    {
      if (my_is_op(str[i + 1]) == 0 && my_is_op(str[i]) == 0)
	{
	 my_puterror("Syntaxe error. Please check operators.")
	 return (-1);
	}
    }
  return (0);
}

int	check_errors(char *str)
{
  int	par;

  par = check_parenthesis(str);
  error = par;
  par += check_op(str);
  if (error != 0)
    {
      my_puterror("Usage : ./a.out 'operation'");
      return (-1)
    }
  return (0);
}
