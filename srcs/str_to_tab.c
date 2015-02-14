/*
** str_to_tab.c for str_to_tab in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 11:45:34 2014 Danilov Dimitri
** Last update Fri Dec 26 20:15:36 2014 Danilov Dimitri
*/

#include "my.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int             nbr_int(char *str)
{
  int   nbr_int;
  int   j;

  j = 0;
  nbr_int = 0;
  while (str[j] != '\0')
    {
      if (str[j] == ' ' && str[j + 1] != '\0')
        {
          nbr_int++;
	}
      j = j + 1;
    }
  return (nbr_int);
}

void	size_of_tab(t_tools *tool, char *path)
{
  int	ok;
  int	fd;
  char	*line;

  ok = 0;
  tool->size_x = 0;
  tool->size_y = 0;
  if ((fd = open(path, O_RDONLY)) == (-1))
    exit(1);
  while ((line = get_next_line(fd)))
    {
      if (ok == 1 && tool->size_x != nbr_int(line))
	{
	  my_putstr("Line are not all in the same size. Exiting....\n");
	  exit(1);
	}
      tool->size_x = nbr_int(line);
      ok = 1;
      tool->size_y++;
      free(line);
    }
  close(fd);
}

int             zero(int *a, int *j)
{
  *a = 0;
  *j = 0;
  return (0);
}

void            str_to_tab(t_tools *tool, char *path, t_init *init)
{
  if ((init->fd = open(path, O_RDONLY)) == (-1))
    exit(1);
  while ((init->line = get_next_line(init->fd)))
    {
      init->size = nbr_int(init->line);
      zero(&init->a, &init->j);
      while (init->a <= init->size)
        {
          tool->tab[init->i][init->a] = (my_getnbr(init->line, &init->j));
	  if (tool->tab[init->i][init->a] == 2)
	    {
	      tool->pos_x = init->i;
	      tool->pos_y = init->a;
	    }
	  init->a++;
        }
      free(init->line);
      init->i++;
    }
  close(init->fd);
  tool->taille_i = init->i;
  tool->taille_j = init->a;
}
