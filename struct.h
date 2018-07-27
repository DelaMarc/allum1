/*
** struct.h for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 13:24:23 2015 Marc DELAUNAY
** Last update Wed Feb 18 14:37:23 2015 Marc DELAUNAY
*/

#ifndef SYSTEM_H_
#define SYSTEM_H_

# define GNL 64

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_alum
{
  int	lines;
  int	cols;
  int	sticks;
  int	player;
}	t_alum;

typedef struct	s_ia
{
  unsigned int	lcol[2];
  int		difficult;
  int		ab[2];
}	t_ia;

typedef struct	s_gnl
{
  int	len;
}	t_gnl;

typedef struct	s_system
{
  t_alum	alum;
  t_ia		ia;
  t_gnl		gnl;
}		t_system;

char	*get_next_line(const int, t_system*);
char	*my_strdup(char*);

void	my_putchar(char);
int	my_strcmp(char*, char*);

#endif /* !SYSEM_H_ */
