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

int	print_str(va_list);
int	print_unsign(va_list);
int	print_char(va_list);
int	print_nb(va_list);
int	print_putS(va_list);
int	print_octal(va_list);
int	print_bin(va_list);
int	print_hexa_min(va_list);
int	print_hexa_maj(va_list);
int	printprc(va_list);
int	my_putunsign_base(unsigned int, char*);
int	aff_char(int, int);
int	print_ptr(va_list*);
int	spaces(int);
int	val_ptr(unsigned long, int);
int	my_putptr_base(unsigned long, char*);

#endif
