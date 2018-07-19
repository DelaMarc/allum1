/*
** multi.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Tue Feb 17 16:31:33 2015 Marc DELAUNAY
** Last update Wed Feb 18 14:40:13 2015 Marc DELAUNAY
*/

#include "struct.h"
#include "my.h"

int	mode(t_system *sys)
{
  char	*str;
  int	i;

  i = 0;
  aff_msg(3);
  while (i == 0)
    {
      str = get_next_line(0, sys);
      if (my_strcmp(str, "solo") == 0)
	i = 1;
      else if (my_strcmp(str, "multi") == 0)
	i = 2;
      else
	{
	  my_printf("Sorry, I do not understand.");
	  aff_msg(3);
	}
      free(str);
    }
  return (i);
}

int	multi_prompt(char **tab, t_system *sys)
{
  while (sys->alum.lines < 0)
    sys->alum.lines = select_line(sys);
  while (sys->alum.cols <= 0)
    sys->alum.cols = select_col(sys);
  if (check_play(tab, sys) < 0)
    {
      sys->alum.lines = -1;
      sys->alum.cols = -1;
      return (prompt(tab, sys));
    }
  sys->alum.player += 1;
  my_printf("Player %d played:\n", sys->alum.player % 2 + 1);
  aff_tab(tab);
  if (sys->alum.sticks == 1)
    return (aff_msg(9));
  if (sys->alum.sticks <= 0)
    return (aff_msg(8));
  if (sys->alum.sticks <= 1)
    {
      if (sys->alum.player % 2 == 0)
	return (aff_msg(9));
      else
	return (aff_msg(8));
    }
}

int	multiplayer(char **tab, t_system *sys)
{
  if (mode(sys) == 1)
    return (1);
  sys->alum.player = 1;
  sys->alum.sticks = 36;
  tab = init_allum(tab);
  aff_tab(tab);
  while (sys->alum.sticks > 1)
    {
      multi_prompt(tab, sys);
      sys->alum.lines = -1;
      sys->alum.cols = -1;
    }
  if (playagain(sys) == 1)
    {
      free_tab(tab);
      return (multiplayer(tab, sys));
    }
  else
    {
      free_tab(tab);
      return (0);
    }
}
