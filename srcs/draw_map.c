/*
** draw_map.c for draw_map in /home/danilo_d/rendu/MUL_2014_wolf3d
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec 20 14:54:34 2014 Danilov Dimitri
** Last update Fri Dec 26 23:05:08 2014 Danilov Dimitri
*/

#include "my.h"

void	draw_map(t_tools *tool)
{
  int	i;
  int	j;
  int	coord_x;
  int	coord_y;

  i = 0;
  coord_x = (HEIGHT / 2) + (HEIGHT / 4);
  while (i != tool->size_y) 
    {
      j = 0;
      coord_y = 25;
      while (j != tool->size_y)
	{
	  if (tool->tab[i][j] == 2)
            put_square(tool, coord_x, coord_y, 2);
	  else if (tool->tab[i][j] == 0)
	    put_square(tool, coord_x, coord_y, 0);
	  else if (tool->tab[i][j] == 1)
            put_square(tool, coord_x, coord_y, 1);
	  j++;
	  coord_y += (HEIGHT / tool->size_y) / 4;
	}
      coord_x += HEIGHT / tool->size_y / 4;
      i++;
    }
}

void	put_square(t_tools *tool, int coord_x, int coord_y, int flag)
{
  int	i;
  int	j;
  int	tmp;

  tmp = coord_y;
  i = 0;
  j = 0;
  while (j != HEIGHT / tool->size_y / 4)
    {
      i = 0;
      coord_y = tmp;
      while (i != HEIGHT / tool->size_y / 4)
	{
	  if (flag == 0)
	    put_white_pixel(tool, coord_y, coord_x);
	  if (flag == 1)
	    put_blue_pixel(tool, coord_y, coord_x);
	  if (flag == 2)
	    put_red_pixel(tool, coord_y, coord_x);
	  coord_y++;
	  i++;
	}
      j++;
      coord_x++;
    }
}
