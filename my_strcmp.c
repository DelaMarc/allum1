/*
** my_strcmp.c for my_strcmp in /home/delaun_m/rendu/Piscine_C_J06/ex_05
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Mon Oct  6 15:42:27 2014 Marc DELAUNAY
** Last update Tue Feb 17 15:41:31 2015 Marc DELAUNAY
*/

#include "my.h"
#include "struct.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) <= 1)
    return (-1);
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] == 0 || s2[i] == 0)
	return (-1);
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (s1[i] != 0 || s2[i] != 0)
    return (-1);
  return (0);
}
