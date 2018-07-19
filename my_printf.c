/*
** my_printf.c for my_printf in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Thu Nov  6 18:27:40 2014 Marc DELAUNAY
** Last update Fri Nov 14 18:23:47 2014 Marc DELAUNAY
*/

#include <stdarg.h>
#include "my.h"
#include "print.h"

int	verif_flag(char *str, char c)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] == c)
	return (a);
      a++;
    }
  return (-1);
}

int	flags(int c, va_list list)
{
  int	(*tab[11])();

  tab[0] = &print_nb;
  tab[1] = &print_str;
  tab[2] = &print_hexa_min;
  tab[3] = &print_hexa_maj;
  tab[4] = &print_octal;
  tab[5] = &print_char;
  tab[6] = &print_bin;
  tab[7] = &print_unsign;
  tab[8] = &print_putS;
  tab[9] = &print_nb;
  tab[10] = &print_ptr;
  return (tab[c](list));
}

int	loop(const char *format, int a, int nb, va_list list)
{
  while (format[nb] != '\0')
    {
      if (format[nb] == '%' && format[nb + 1] == '%')
	{
	  my_putchar('%');
	  nb += 2;
	  a++;
	}
      if (format[nb] == '%' && verif_flag("dsxXocbuSip", format[nb + 1]) >= 0)
	{
	    a += flags(verif_flag("dsxXocbuSip",
				  format[nb + 1]), list);
	    a--;
	    nb += 1;
	}
      else
	my_putchar(format[nb]);
      nb++;
      a++;
    }

  va_end(list);
  return (a);
}

int	my_printf(const char *format, ...)
{
  va_list	list;
  int		nb;
  int		a;

  va_start(list, format);
  a = 0;
  nb = 0;
  return (loop(format, a, nb, list));
}
