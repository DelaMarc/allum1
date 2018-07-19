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

int	print_str(va_list list)
{
  char	*a;

  a = va_arg(list, char*);
  my_putstr(a);
  return (my_strlen(a));
}

int	print_octal(va_list list)
{
  unsigned int	a;

  a = va_arg(list, unsigned int);
  my_putunsign_base(a, "01234567");
  return (aff_char(a, 8));
}

int	print_bin(va_list list)
{
  unsigned int	a;

  a = va_arg(list, unsigned int);
  my_putunsign_base(a, "01");
  return (aff_char(a, 2));
}

int	print_hexa_min(va_list list)
{
  unsigned int	a;

  a = va_arg(list, unsigned int);
  my_putunsign_base(a, "0123456789abcdef");
  return (aff_char(a, 16));
}

int	print_hexa_maj(va_list list)
{
  unsigned int	a;

  a = va_arg(list, unsigned int);
  my_putunsign_base(a, "0123456789ABCDEF");
  return (aff_char(a, 16));
}
