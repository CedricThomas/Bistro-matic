/*
** get_oper.c for get_oper in /home/arthur/c/CPool_evalexpr/
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Oct 31 10:30:26 2016 Arthur Knoepflin
** Last update Tue Nov  1 22:37:16 2016 Arthur Knoepflin
*/
#include "my.h"
#include "bistro.h"

int	is_oper(char c, char *oper_list)
{
  int	i;

  i = 0;
  while (oper_list[i])
    {
      if (c == oper_list[i])
	return (1);
      i += 1;
    }
  return (0);
}

int	is_op_prio(char c, char *op)
{
  if (c == op[OP_MULT_IDX] || c == op[OP_DIV_IDX] ||
      c == op[OP_MOD_IDX])
    return (1);
  return (0);
}

int	is_op_nprio(char c, char *op)
{
  if (c == op[OP_DIV_IDX] || c == op[OP_SUB_IDX])
    return (1);
  return (0);
}

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
