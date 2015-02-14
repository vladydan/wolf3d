/*
** move.c for move in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Dec 23 22:00:06 2014 Danilov Dimitri
** Last update Fri Dec 26 22:43:43 2014 Danilov Dimitri
*/

#include "my.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void	pos_look(int key, t_tools *tool)
{
  if (key == R)
    {
      if (tool->pos_look < LENGHT / 2 + LENGHT / 4)
	tool->move.look_up = 1;
    }
  if (key == F)
    {
      if (tool->pos_look > LENGHT / 2 - LENGHT / 4)
        tool->move.look_down = 1;
    }
}

void	move_down_bis(t_tools *tool)
{
  int   tmp;
  int   tmp2;
  int   x;
  int   y;

  x = tool->pos_x;
  y = tool->pos_y;
  tmp = tool->pos_x - (0.3 * cos((tool->angle / 180) * M_PI));
  tmp2 =tool->pos_y - (0.3 * sin((tool->angle / 180) * M_PI));
  if (tool->tab[tmp][tmp2] == 0 || tool->tab[tmp][tmp2] == 2)
    {
      tool->tab[x][y] = 0;
      x = tool->pos_x = tool->pos_x - (tool->speed * cos((tool->angle / 180) * M_PI));
      y = tool->pos_y = tool->pos_y - (tool->speed * sin((tool->angle / 180) * M_PI));
      tool->tab[x][y] = 2;
    }
}

void	move_up_bis(t_tools *tool)
{
  int   tmp;
  int   tmp2;
  int   x;
  int   y;
  
  x = tool->pos_x;
  y = tool->pos_y;
  tmp = tool->pos_x + (0.3 * cos((tool->angle / 180) * M_PI));
  tmp2 = tool->pos_y + (0.3 * sin((tool->angle / 180) * M_PI));
  if (tool->tab[tmp][tmp2] == 0 || tool->tab[tmp][tmp2] == 2)
    {
      tool->tab[x][y] = 0;
      x = tool->pos_x = tool->pos_x + (tool->speed * cos((tool->angle / 180) * M_PI));
      y = tool->pos_y = tool->pos_y + (tool->speed * sin((tool->angle / 180) * M_PI));
      tool->tab[x][y] = 2;
    }
}

int	move(t_tools *tool)
{
  if (tool->ok == 1)
    {
      usleep(1000);
      if (tool->move.sprint == 1)
	tool->speed = 0.04;
      if (tool->move.up == 1)
	move_up_bis(tool);
      if (tool->move.right == 1)
	tool->angle = tool->angle - 1;
      if (tool->move.left == 1)
	tool->angle = tool->angle + 1;
      if (tool->move.back == 1)
	move_down_bis(tool);
      if (tool->move.look_up == 1)
	tool->pos_look += 5;
      if (tool->move.look_down == 1)
        tool->pos_look -= 5;
      wolf3d(tool);
    }
  return (0);
}
