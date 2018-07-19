/*
** my_put_nbr.c for my_put_nbr in /home/delaun_m/rendu/Piscine_C_J03
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Wed Oct  1 22:11:38 2014 Marc DELAUNAY
** Last update Fri Nov 14 18:21:42 2014 Marc DELAUNAY
*/

#include "my.h"

int	 my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    {
      my_putchar(nb + 48);
    }
  return (0);
}
