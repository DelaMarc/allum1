/*
** my_putnbr_base.c for all in /home/delaun_m/rendu/PSU_2014_my_printf
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Wed Nov 12 19:09:27 2014 Marc DELAUNAY
** Last update Fri Nov 14 16:01:15 2014 Marc DELAUNAY
*/

#include "my.h"

int	my_putnbr_base(int nb, char *base)
{
  int	size;

  size = my_strlen(base);
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= size)
    {
      my_putnbr_base(nb / size, base);
      my_putnbr_base(nb % size, base);
    }
  else
      my_putchar(base[nb]);
  return (0);
}

int	my_putunsign_base(unsigned int nb, char *base)
{
  unsigned int	size;

  size = my_strlen(base);
  if (nb >= size)
    {
      my_putunsign_base(nb / size, base);
      my_putunsign_base(nb % size, base);
    }
  else
      my_putchar(base[nb]);
  return (0);
}

int	my_putptr_base(unsigned long nb, char *base)
{
  unsigned long	size;

  size = my_strlen(base);
  if (nb >= size)
    {
      my_putptr_base(nb / size, base);
      my_putptr_base(nb % size, base);
    }
  else
      my_putchar(base[nb]);
  return (0);
}
