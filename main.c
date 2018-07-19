/*
** main.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 13:27:45 2015 Marc DELAUNAY
** Last update Wed Feb 18 23:35:48 2015 Marc DELAUNAY
*/

#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"

int	modify_try(char **tab, int *lcol, int remain)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  if (lcol[1] > remain)
    return (remain -1);
  if (lcol[1] == 0)
    lcol[1]++;
  while (tab[lcol[0]][i] != 0)
    {
      if (tab[lcol[0]][i] == '|')
	{
	  tab[lcol[0]][i] = ' ';
	  a++;
	  if (a == (int) lcol[1])
	    return (lcol[1]);
	}
      i++;
    }
  return (lcol[1]);
}

int	prompt(char **tab, t_system *sys)
{
  int	*a;

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
  aff_tab(tab);
  my_printf("il reste %d allums\n", sys->alum.sticks);
  if (sys->alum.sticks == 1)
    return (aff_msg(4));
  if (sys->alum.sticks <= 0)
    return (aff_msg(5));
  aff_msg(2);
  a = auto_try(tab, sys);
  sys->alum.sticks -= modify_try(tab, a, sys->alum.sticks);
  aff_tab(tab);
  my_printf("il reste %d allums\n", sys->alum.sticks);
  if (sys->alum.sticks <= 1)
    return (aff_msg(5));
}

char	**init_allum(char **tab)
{
  if ((tab[0] = my_strdup("     |")) == NULL)
    return (NULL);
  if ((tab[1] = my_strdup("    |||")) == NULL)
    return (NULL);
  if ((tab[2] = my_strdup("   |||||")) == NULL)
    return (NULL);
  if ((tab[3] = my_strdup("  |||||||")) == NULL)
    return (NULL);
  if ((tab[4] = my_strdup(" |||||||||")) == NULL)
    return (NULL);
  if ((tab[5] = my_strdup("|||||||||||")) == NULL)
    return (NULL);
  tab[6] = NULL;
  return (tab);
}

int	main()
{
  t_system	sys;
  char		**tab;

  if ((tab = malloc(sizeof(char*) * 7)) == NULL)
    return (0);
  sys.alum.lines = -1;
  sys.alum.cols = -1;
  if (multiplayer(tab, &sys) == 1)
    start_game(tab, &sys);
  free(tab);
  return (0);
}
