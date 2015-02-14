/*
** save.c for save in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Dec 24 10:55:47 2014 Danilov Dimitri
** Last update Fri Jan  2 08:28:12 2015 Danilov Dimitri
*/

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include <unistd.h>

int	save(t_tools *tool)
{
  int   fd;
  int	i;
  int	j;
  int	data;

  i = -1;
  fd = open(tool->arg, O_RDWR | O_TRUNC);
    if (fd == -1)
      exit(1);
  while (++i != tool->size_y)
    {
      j = -1;
      while (++j != tool->size_y)
	{
	  data = tool->tab[i][j] + 48;
	  write(fd, &data, 1);
	  if (j + 1 != tool->size_y)
	    write (fd, " ", 1);
	}
      write (fd, "\n", 1);
    }
  close(fd);
  return (0);
}
