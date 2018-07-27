/*
** print.h for printf in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Wed Nov 12 18:23:21 2014 Marc DELAUNAY
** Last update Fri Nov 14 15:07:06 2014 Marc DELAUNAY
*/

#include <stdarg.h>

#ifndef PRINT_H_
#define PRINT_H_

int	print_nb(va_list);
int	print_str(va_list);
int	aff_char(int, int);
int	my_put_nbr(int);

#endif
