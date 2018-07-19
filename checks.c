/*
** checks.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 14:01:34 2015 Marc DELAUNAY
** Last update Wed Feb 18 15:37:32 2015 Marc DELAUNAY
*/

#include <stdio.h>
#include "struct.h"
#include "my.h"

int	check_content(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != ' ')
	return (0);
      i++;
    }
  return (1);
}

int	modify_tab(char **tab, t_system *sys)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (tab[sys->alum.lines][i] != 0)
    {
      if (tab[sys->alum.lines][i] == '|')
	{
	  tab[sys->alum.lines][i] = ' ';
	  a++;
	  sys->alum.sticks -= 1;
	  if (a == sys->alum.cols)
	    return (0);
	}
      i++;
    }
  return (0);
}

int	count_allum(char *str)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    {
      if (str[i] == '|')
	a++;
      i++;
    }
 return (a);
}

int	check_buffer(char *buffer, int nb)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] < '0' || buffer[i] > '9')
	return (-1);
      i++;
    }
  if ((nb = my_getnbr(buffer) - 1) == 0)
    return (my_putstr("cannot select 0\n") * (-1));
  return (nb);
}

int	check_play(char **tab, t_system *sys)
{
  if (sys->alum.lines < 0 || sys->alum.lines > 6)
    return (my_putstr("invalid line selected\n") * (-1));
  if (check_content(tab[sys->alum.lines]) == 1)
    return (my_putstr("there's no stick to remove on this line\n") * (-1));
  if (count_allum(tab[sys->alum.lines]) < sys->alum.cols)
    return (my_putstr("you've selected too much sticks\n") * (-1));
  return (modify_tab(tab, sys));
}
