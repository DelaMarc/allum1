/*
** my.h for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
** 
** Made by Marc DELAUNAY
** Login   <delaun_m@epitech.net>
** 
** Started on  Fri Feb 13 19:03:36 2015 Marc DELAUNAY
** Last update Wed Feb 18 20:14:29 2015 Marc DELAUNAY
*/

#ifndef MY_H_
# define MY_H_

#include "struct.h"

void	aff_tab(char**);
int	my_putstr(char*);
int	aff_msg(int);
void	free_tab(char**);
int	check_content(char*);
int	modify_tab(char**, t_system*);
int	count_allum(char*);
int	check_buffer(char*, int);
int	check_play(char**, t_system*);
int	prompt(char**, t_system*);
char	**init_allum(char**);
char	*my_strdup(char*);
int	select_line(t_system*);
int	select_col(t_system*);
int	playagain(t_system*);
int	my_strlen(char*);
char	**copy_tab(char**);
int	modify_try(char**, int*, int);
int	*auto_try(char**, t_system*);

int	multiplayer(char**, t_system*);
int	my_strlen(char*);
int	my_getnbr(char*);
int	my_printf(const char*, ...);
int	start_game(char**, t_system*);

#endif /* !MY_H_ */
