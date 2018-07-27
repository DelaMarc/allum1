##
## Makefile for allum1 in /home/delaun_m/clone_army/CPE_2014_allum1
## 
## Made by Marc DELAUNAY
## Login   <delaun_m@epitech.net>
## 
## Started on  Fri Feb 13 18:52:44 2015 Marc DELAUNAY
## Last update Wed Feb 18 23:37:24 2015 Marc DELAUNAY
##

NAME	= allum1

SRC	= display.c \
	  checks.c \
	  get_next_line.c \
	  main.c \
	  my_strdup.c \
	  opponent.c \
	  affs.c \
	  char_aff.c \
	  difficult.c \
	  my_put_nbr.c \
	  my_printf.c \
	  my_strcmp.c \
	  multi.c \
	  my_getnbr.c \
	  selects.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME);

re: fclean all
