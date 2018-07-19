/*
** my_strdup.c for minishell1 in /home/delaun_m/clone_army/CPE_2014_Pushswap
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Sat Jan 24 13:30:07 2015 Marc DELAUNAY
** Last update Sat Feb 14 14:05:16 2015 Marc DELAUNAY
*/

#include "struct.h"
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
