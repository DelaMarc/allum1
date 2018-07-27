/*
** char_aff.c for printf in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Thu Nov 13 15:02:53 2014 Marc DELAUNAY
** Last update Mon Feb 16 17:22:29 2015 Marc DELAUNAY
*/

#include "my.h"
#include "print.h"

int	aff_char(int nb, int base)
{
  int	i;

  i = 0;
  if (nb < 0)
    return (aff_char(-nb, base) + 1);
  while (nb >= base)
    {
      nb = nb / base;
      i++;
    }
  return (i + 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
