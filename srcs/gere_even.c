/*
** gere_even.c for gere_even in /home/danilo_d/MUL_2014_fdf/srcs
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 18:25:55 2014 Dimitri Danilov
** Last update Fri Jan  2 08:56:36 2015 Danilov Dimitri
*/

#include "my.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int             gere_key(int key , t_tools *tool)
{
  if (tool->ok == 1)
    {
      if (key == ECHAP)
	{
	  free(tool);
	  exit(0);
	}
      if (key == ARR_U || key == Z)
	tool->move.up = 1;
      if (key == 65364 || key == BACK)
	tool->move.back = 1;
      if (key == ARR_L || key == Q)
	tool->move.left = 1;
      if (key == ARR_R || key == D)
	tool->move.right = 1;
      if (key == SHIFT)
	tool->move.sprint = 1;
      pos_look(key, tool);
    }
  return (0);
}

int     gere_key2(int key, t_tools *tool)
{
  if (key == ECHAP)
    exit(1);
  if (key == S)
    {
      save(tool);
      exit(1);
    }
  return (0);
}

int		gere_button(int button, int x, int y, t_tools *tool)
{
  if (tool->ok != 1)
    {
      if (x > 122 && x < 560 && y > 48 && y < 200 && button == 1)
	{
	  tool->ok = 1;
	  segfault_protector(tool);
	  wolf3d(tool);
	}
      if (x > 122 && x < 560 && y > 212 && y < 320 && button == 1)
	{
	  if (tool->size_y < 3)
	    {
	      my_putstr("Error, the map must be atleast 3*3 long\n");
	      exit(1);
	    }
	  map_creator(tool);
	}
      if (x > 122 && x < 560 && y > 348 && y < 509 && button == 1)
	exit(1);
    }
  return (0);
}

int		gere_key_release(int key, t_tools *tool)
{
  if (key == Z)
    tool->move.up = 0;
  if (key == BACK)
    tool->move.back = 0;
  if (key == Q)
    tool->move.left = 0;
  if (key == D)
    tool->move.right = 0;
  if (key == SHIFT)
    {
      tool->speed = 0.01;
      tool->move.sprint = 0;
    }
  if (key == R)
    tool->move.look_up = 0;
  if (key == F)
    tool->move.look_down = 0;
  return (0);
}

int             gere_expose(t_tools *tool)
{
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->menu.img, 0, 0);
  return (0);
}
