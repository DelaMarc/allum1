/*
** my_getnbr.c for my_getnbr in /home/delaun_m/rendu/Piscine_C_J04
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Thu Oct  2 22:50:26 2014 Marc DELAUNAY
** Last update Wed Feb 18 15:48:13 2015 Marc DELAUNAY
*/

int	my_sign(char c)
{
  if (c == '-')
    {
      return (-1);
    }
  else
    {
      return (1);
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	a;
  int	tens;

  i = my_strlen(str) - 1;
  tens = 1;
  a = 0;
  while (i >= 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      a += ((str[i] - 48) * tens);
      i--;
      tens *= 10;
    }
  return (a * my_sign(str[0]));
}
