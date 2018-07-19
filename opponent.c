/*
** opponent.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Sat Feb 14 14:11:44 2015 Marc DELAUNAY
** Last update Wed Feb 18 20:16:41 2015 Marc DELAUNAY
*/

#include <math.h>
#include "struct.h"
#include "my.h"

int	*random_try(char **tab, t_system *sys)
{
  sys->ia.lcol[0] = (rand() % 5) + 1;
  while (count_allum(tab[sys->ia.lcol[0]]) == 0)
    {
      sys->ia.lcol[0] = (rand() % 5) + 1;
    }
  sys->ia.lcol[1] = (rand() % count_allum(tab[sys->ia.lcol[0]])) + 1;
  if (sys->ia.lcol[1] == 0)
    sys->ia.lcol[1] = 1;
  return ((int*)sys->ia.lcol);
}

int	try_game(char **tab, t_system *sys, int less)
{
  int	alums;
  int	play;

  alums = sys->alum.sticks - less;
  play = 0;
  while (alums > 1)
    {
      alums -= modify_try(tab, random_try(tab, sys), alums);
      play++;
    }
  free_tab(tab);
  free(tab);
  if ((play % 2) == 0)
    return (play);
  else
    return (0);
}

int	percent(char **tab, int k, int l, t_system *sys)
{
  int	i;
  char	**tmp;
  int	a;
  int	lcol[2];

  lcol[0] = k;
  lcol[1] = l;
  a = 0;
  i = 0;
  while (i < sys->ia.difficult)
    {
      tmp = copy_tab(tab);
      modify_try(tmp, lcol, sys->alum.sticks);
      if (try_game(tmp, sys, l) != 0)
	a++;
      i++;
    }
  return (a);
}

int	*auto_try(char **tab, t_system *sys)
{
  int	ijk[3];
  int	a;
  int	b;

  a = 0;
  ijk[0] = 0;
  ijk[1] = 1;
  while (tab[ijk[0]] != NULL)
    {
      while ((ijk[2] = count_allum(tab[ijk[0]])) == 0
	     && tab[ijk[0] + 1] != NULL)
	ijk[2] = count_allum(tab[ijk[0]++]);
      while (ijk[1] < ijk[2])
	{
	  if (a < (b = percent(tab, ijk[0], ijk[1], sys)))
	    {
	      a = b;
	      sys->ia.ab[0] = ijk[0];
	      sys->ia.ab[1] = ijk[1];
	    }
	  ijk[1]++;
	}
      ijk[0]++;
    }
  return (sys->ia.ab);
}
