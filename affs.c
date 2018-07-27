/*
** affs.c for my_printf in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Wed Nov 12 10:16:37 2014 Marc DELAUNAY
** Last update Fri Nov 14 15:29:27 2014 Marc DELAUNAY
*/

#include <stdarg.h>
#include "my.h"
#include "print.h"

int	print_nb(va_list list)
{
  int	a;

  a = va_arg(list, int);
  my_put_nbr(a);
  return (aff_char(a, 10));
}

int	print_str(va_list list)
{
  char	*a;

  a = va_arg(list, char*);
  my_putstr(a);
  return (my_strlen(a));
}
