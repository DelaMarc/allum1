/*
** affs.c for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 14:44:59 2015 Marc DELAUNAY
** Last update Wed Feb 18 23:32:42 2015 Marc DELAUNAY
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	aff_tab(char **tab)
{
  int	i;
  int	a;

  i = 0;
  a = 1;
  while (tab[i] != 0)
    {
      my_printf("%d) %s\n", a, tab[i]);
      i++;
      a++;
    }
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      write(1, &str[i], 1);
      i++;
    }
  return (i);
}

int	aff_msg(int i)
{
  char	*tab[10];

  tab[0] = "select the line where you want to remove a stick: ";
  tab[1] = "how many sticks do you want to remove? ";
  tab[2] = "your opponent played:\n";
  tab[3] = "Select a mode: solo/multi  ";
  tab[4] = "You win!\n";
  tab[5] = "You lose!\n";
  tab[6] = "Player 1 played:\n";
  tab[7] = "Player 2 played:\n";
  tab[8] = "Player 1 win!\n";
  tab[9] = "Player 2 win!\n";
  return (my_putstr(tab[i]));
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
}

char	**copy_tab(char **tab)
{
  int	i;
  char	**new;

  i = 0;
  if ((new = malloc(sizeof(char*) * 7)) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      if ((new[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  new[i] = NULL;
  return (new);
}
