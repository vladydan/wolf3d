/*
** segfault_protector.c for segfault_protector in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Dec 24 12:30:32 2014 Danilov Dimitri
** Last update Wed Dec 24 13:10:48 2014 Danilov Dimitri
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int		error(t_tools *tool, int i, int j)
{
  int	pos;

  pos = 0;
  if (tool->tab[i][j] == 2)
      pos = 1;
  if (tool->tab[0][j] != 1 ||
      tool->tab[i][0] != 1 ||
      tool->tab[tool->size_y - 1][j] != 1 ||
      tool->tab[i][tool->size_y - 1] != 1)
    {
      my_putstr(ERROR);
      exit(1);
    }
  return (pos);
}

int		segfault_protector(t_tools *tool)
{
  int	i;
  int	j;
  int	pos;

  pos = 0;
  i = -1;
  while (++i != tool->size_y)
    {
      j = -1;
	while (++j != tool->size_y) 
	  {
	    pos = pos + error(tool, i, j);
	    if (pos == 2)
	      {
		my_putstr("There are two differents spawns.\n");
		exit(1);
	      }
	  }
    }
  if (pos == 0)
    {
      my_putstr("There is no spawn.\n");
      exit(1);
    }
  return (0);
}
