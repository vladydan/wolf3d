/*
** map_creator.c for map_creator in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Dec 23 13:40:32 2014 Danilov Dimitri
** Last update Fri Dec 26 23:08:29 2014 Danilov Dimitri
*/

#include "my.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdlib.h>

void	fill_tab(t_tools *tool)
{
  int	i;
  int	j;

  i = 0;
  while (i != HEIGHT)
    {
      j = 0;
      while (j != HEIGHT)
	{ 
	  tool->tab_pos[i][j].x = 0;
          tool->tab_pos[i][j].y = 0;
	  j++;
	}
      i++;
    }
}

int	new_pos(int button, int x, int y, t_tools *tool)
{
  if (tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] == 1 &&
      button == 1)
    tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] = 0;
  else if (tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] == 0 &&
	   button == 1)
    tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] = 1;
  if (tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] != 2 &&
      button == 3)
    tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] = 2;
  else if (tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] == 2 &&
	   button == 3)
    tool->tab[tool->tab_pos[x][y].x][tool->tab_pos[x][y].y] = 0;
  clear_screen(tool);
  create_map(tool);
  return (0);
}

void	create_map(t_tools *tool)
{
  t_mini_map	*map;

  map = xmalloc(sizeof(*map));
  map->i = 0;
  map->coord_x = 50;
  while (map->i != tool->size_y) 
    {
      map->j = 0;
      map->coord_y = 50;
      while (map->j != tool->size_y)
	{
	  if (tool->tab[map->i][map->j] == 2)
            put_big_square(tool, *map, 2);
	  else if (tool->tab[map->i][map->j] == 0)
	    put_big_square(tool, *map, 0);
	  else if (tool->tab[map->i][map->j] == 1)
            put_big_square(tool, *map, 1);
	  map->j++;
	  map->coord_y += ((LENGHT / 2) / tool->size_x);
	}
      map->coord_x += ((LENGHT / 2) / tool->size_x);
      map->i++;
    }
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->mg.img, 0, 0);
}

void	put_big_square(t_tools *tool, t_mini_map map, int flag)
{
  int	i;
  int	j;
  int	tmp;

  tmp = map.coord_y;
  j = -1;
  while (++j != (LENGHT / 2) / tool->size_x)
    {
      i = 0;
      map.coord_y = tmp;
      while (i != (LENGHT / 2) / tool->size_x)
	{
	  tool->tab_pos[map.coord_y][map.coord_x].x = map.i;
          tool->tab_pos[map.coord_y][map.coord_x].y = map.j;
	  if (flag == 0)
	    put_white_pixel(tool, map.coord_y, map.coord_x);
	  if (flag == 1)
	    put_blue_pixel(tool, map.coord_y, map.coord_x);
	  if (flag == 2)
	    put_red_pixel(tool, map.coord_y, map.coord_x);
	  map.coord_y++;
	  i++;
	}
      map.coord_x++;
    }
}

void		map_creator(t_tools *tool)
{
  int		i;

  i = 0;
  tool->tab_pos = xmalloc(sizeof(*tool->tab_pos) * HEIGHT);
  while (i != LENGHT)
    {
      tool->tab_pos[i] = xmalloc(sizeof(**tool->tab_pos) * HEIGHT);
      i++;
    }
  fill_tab(tool);
  create_map(tool);
  mlx_hook(tool->ml.window, ButtonPress, ButtonPressMask, &new_pos, tool);
  mlx_hook(tool->ml.window, KeyPress, KeyPressMask, &gere_key2, tool);
  mlx_loop(tool->ml.ptr);
}
