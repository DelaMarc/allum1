/*
** affs2.c for  in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Nov 14 15:24:22 2014 Marc DELAUNAY
** Last update Fri Nov 14 18:32:25 2014 Marc DELAUNAY
*/

#include <stdarg.h>
#include "my.h"
#include "print.h"

int	print_char(va_list list)
{
  int	a;

  a = va_arg(list, int);
  my_putchar(a);
  return (1);
}

int	print_unsign(va_list list)
{
  unsigned int	a;

  a = va_arg(list, unsigned int);
  my_putunsign(a);
  return (aff_char(a, 10));
}

int	my_putS(char *str)
{
  int	a;
  int	i;

  i = 0;
  a = 0;
  while (str[a])
    {
      if (str[a] <= 31 || str[a] == 127)
	{
	  i += spaces(str[a]);
	  my_putchar('\\');
	  i += (aff_char(str[a], 8) + 1);
	}
      else
	{
	  my_putchar(str[a]);
	  a++;
	  i++;
	}
    }
  return (i);
}

int	print_putS(va_list list)
{
  char	*a;

  a = va_arg(list, char*);
  return (my_putS(a));
}

int	my_putunsign(unsigned int nb)
{
  if (nb >= 10)
    {
      my_putunsign(nb / 10);
      my_putunsign(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}
