/*
** put_pixel.c for put_pixel in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Fri Dec 26 23:17:26 2014 Danilov Dimitri
** Last update Fri Dec 26 23:20:01 2014 Danilov Dimitri
*/

#include "my.h"

int     put_blue_pixel(t_tools *ptr, int  x, int y)
{
  int   i;

  i = (ptr->mg.sizeline * y) + (x * (ptr->mg.bpp / 8));
  ptr->mg.data[i] = 250;
  ptr->mg.data[i + 1] = 0;
  ptr->mg.data[i + 2] = 0;
  return (0);
}

int     put_white_pixel(t_tools *ptr, int  x, int y)
{
  int   i;

  i = (ptr->mg.sizeline * y) + (x * (ptr->mg.bpp / 8));
  ptr->mg.data[i] = 250;
  ptr->mg.data[i + 1] = 250;
  ptr->mg.data[i + 2] = 250;
  return (0);
}

int     put_black_pixel(int  x, int y, t_tools *ptr)
{
  int   i;

  i = (ptr->mg.sizeline * y) + (x * (ptr->mg.bpp / 8));
  ptr->mg.data[i] = 0;
  ptr->mg.data[i + 1] = 0;
  ptr->mg.data[i + 2] = 0;
  return (0);
}

int     pixel_copy(t_tools *ptr, int  x, int y, t_image texture)
{
  int   i;
  int	j;
  int	coord_x;
  int	coord_y;

  coord_x = x * 300 / HEIGHT;
  coord_y = y * 300 / HEIGHT;
  i = (ptr->mg.sizeline * y) + (x * (ptr->mg.bpp / 8));
  j = (texture.sizeline * coord_y) + (coord_x * (texture.bpp / 8));
  ptr->mg.data[i] = texture.data[j];
  ptr->mg.data[i + 1] = texture.data[j + 1];
  ptr->mg.data[i + 2] = texture.data[j + 2];
  return (0);
}

int     put_red_pixel(t_tools *ptr, int  x, int y)
{
  int   i;

  i = (ptr->mg.sizeline * y) + (x * (ptr->mg.bpp / 8));
  ptr->mg.data[i] = 0;
  ptr->mg.data[i + 1] = 0;
  ptr->mg.data[i + 2] = 250;
  return (0);
}
