/*
** affs3.c for my_printf in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Thu Nov 13 15:32:18 2014 Marc DELAUNAY
** Last update Fri Nov 14 18:31:59 2014 Marc DELAUNAY
*/

#include "print.h"
#include "my.h"


int	printprc(va_list list)
{
  int	a;

  a = va_arg(list, int);
  my_putchar(a);
  my_putchar('%');
  return (1);
}

int	print_ptr(va_list *ptr)
{
  unsigned long	a;

  my_putstr("0x");
  a = va_arg(*ptr, unsigned long);
  my_putptr_base(a, "0123456789abcdef");
  return (val_ptr(a, 16) + 2);
}

int	spaces(int a)
{
  if (a <= 7)
    {
      my_putchar('0');
      my_putchar('0');
      return (2);
    }
  else if (a > 7 && a <= 31)
    {
      my_putchar('0');
      return (1);
    }
  else
    return (0);
}
