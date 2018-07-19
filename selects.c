/*
** selects.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 15:56:08 2015 Marc DELAUNAY
** Last update Wed Feb 18 15:42:15 2015 Marc DELAUNAY
*/

#include "struct.h"
#include "my.h"

int	select_line(t_system *sys)
{
  char	*str;
  int	i;

  aff_msg(0);
  str = get_next_line(0, sys);
  i = my_getnbr(str) - 1;
  free(str);
  return (i);
}

int	select_col(t_system *sys)
{
  char	*str;
  int	i;

  aff_msg(1);
  str = get_next_line(0, sys);
  i = my_getnbr(str);
  free(str);
  return (i);
}
