/*
** gnl.c for  in /home/delaun_m/rendu/wip/BSQ
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Mon Jan 12 21:07:18 2015 Marc DELAUNAY
** Last update Wed Feb 18 15:36:15 2015 Marc DELAUNAY
*/

#include "struct.h"

int	my_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (i);
}

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i ++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*char_add(char *str, char c)
{
  char	*new_line;
  int	len;

  if (str == NULL)
    len = 0;
  else
    len = my_strlen(str);
  if ((new_line = malloc(len + 2)) == NULL)
    return (NULL);
  if (str != NULL)
    my_strcpy(new_line, str);
  free(str);
  new_line[len] = c;
  new_line[len + 1] = '\0';
  return (new_line);
}

char		*get_next_line(const int fd, t_system *sys)
{
  char		*str;
  static char	buffer[GNL + 1];

  sys->gnl.len = 1;
  buffer[GNL + 1] = 0;
  if ((str = malloc(1)) == NULL)
    return (NULL);
  str[0] = '\0';
  while (sys->gnl.len > 0)
    {
      if (buffer[0] == '\0')
	{
	  sys->gnl.len = read(fd, buffer, GNL);
	  buffer[sys->gnl.len] = '\0';
	}
      if (buffer[0] == '\n')
	{
	  my_strcpy(buffer, buffer + 1);
	  return (str);
	}
      str = char_add(str, buffer[0]);
      my_strcpy(buffer, buffer + 1);
    }
  free(str);
  return (NULL);
}
