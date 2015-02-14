/*
** wolf3d.c for wolf in /home/danilo_d/rendu/MUL_2014_wolf3d
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Dec 17 11:05:31 2014 Danilov Dimitri
** Last update Fri Dec 26 22:57:23 2014 Danilov Dimitri
*/

#include <math.h>
#include "my.h"
#include <stdio.h>
#include "mlx.h"
#include <inttypes.h>
#include <stdlib.h>

void		aff_wolf(t_tools *tool, int x)
{
  int		y;

  y = 0;
  tool->size_of_wall = ((HEIGHT - 1) / (2 * tool->k));
  while (y != abs(tool->pos_look - tool->size_of_wall))
    {
      if (y > 0)
	pixel_copy(tool, x, y, tool->sky);
      y++;
    }
  y = 0;
  while (y != tool->size_of_wall)
    {
      if (tool->pos_look - y >= 2)
  	pixel_copy(tool, x, tool->pos_look - y, tool->texture);
      if (tool->pos_look + y < HEIGHT)
  	pixel_copy(tool, x, tool->pos_look + y, tool->texture);
      y++;
    }
  y = y + tool->pos_look;
  while (y < HEIGHT)
    {
      pixel_copy(tool, x, y, tool->ground);
      y = y + 1;
    }
}

void		calculate_k(t_tools *tool)
{
  tool->k = 1;
  tool->pos_mur_x = tool->pos_x +  (tool->k * tool->vx);
  tool->pos_mur_y = tool->pos_y +  (tool->k * tool->vy);
  while (tool->tab[tool->pos_mur_x][tool->pos_mur_y] != 1)
    {
      tool->pos_mur_x = tool->pos_x +  (tool->k * tool->vx);
      tool->pos_mur_y = tool->pos_y +  (tool->k * tool->vy);
      tool->k = tool->k + 0.01;
    }
}

void		wolf3d(t_tools *tool)
{
  double	x;
  double	angle;

  angle = (tool->angle / 180) * M_PI;
  x = 0;
  tool->x1 = 0.5;
  while (x <= LENGHT)
    {
      tool->y1 = (HEIGHT / 2 - x) / LENGHT;
      tool->X = (tool->x1 * cos(angle)) - (tool->y1 * sin(angle));
      tool->Y = (tool->x1 * sin(angle)) + (tool->y1 * cos(angle));
      tool->X = tool->X + tool->pos_x;
      tool->Y = tool->Y + tool->pos_y;
      tool->vx = tool->X - tool->pos_x;
      tool->vy = tool->Y - tool->pos_y;
      calculate_k(tool);
      aff_wolf(tool, x);
      x++;
    }
  draw_map(tool);
  tool->ok = 1;
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->mg.img, 0, 0);
}
