/*
** diffifult.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Tue Feb 17 11:18:05 2015 Marc DELAUNAY
** Last update Thu Feb 19 11:12:22 2015 Marc DELAUNAY
*/

#include "my.h"
#include "struct.h"

int	check_difficult(char *str)
{
  int	i;
  char	*tab[4];

  tab[0] = "easy";
  tab[1] = "normal";
  tab[2] = "hard";
  tab[3] = NULL;
  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(str, tab[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int	difficult(t_system *sys)
{
  char	*str;
  int	a;

  my_printf("please select a level of difficluty: easy, normal or hard.\n");
  while ((a = check_difficult(str = get_next_line(0, sys))) < 0)
    {
      my_printf("Error in read, please write one of the examples\n");
      my_printf("There may be errors in the orthograph...\n");
      free(str);
    }
  if (a == 0)
    sys->ia.difficult = 300;
  else if (a == 1)
    sys->ia.difficult = 5000;
  else
    sys->ia.difficult = 50000;
  free(str);
  return (0);
}

int	playagain(t_system *sys)
{
  char *str;
  int	i;

  i = 0;
  my_printf("Do you want to play again? (yes/no)\n");
  while (i == 0)
    {
      str = get_next_line(0, sys);
      if (my_strcmp(str, "yes") == 0)
	i = 1;
      else if (my_strcmp(str, "no") == 0)
	i = 2;
      else
	my_printf("Sorry, I do not understand. Do you want to play again?\n");
      free(str);
    }
  return (i);
}

int	start_game(char **tab, t_system *sys)
{
  difficult(sys);
  sys->alum.sticks = 36;
  tab = init_allum(tab);
  aff_tab(tab);
  while (sys->alum.sticks > 1)
    {
      prompt(tab, sys);
      sys->alum.lines = -1;
      sys->alum.cols = -1;
    }
  if (playagain(sys) == 1)
    {
      free_tab(tab);
      return (start_game(tab, sys));
    }
  else
    {
      free_tab(tab);
      return (0);
    }
}
