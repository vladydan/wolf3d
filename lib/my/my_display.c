/*
** my_display.c for display in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Dec  7 12:18:41 2014 Danilov Dimitri
** Last update Fri Dec 26 23:20:27 2014 Danilov Dimitri
*/

#include <unistd.h>
#include "my.h"
#include "mlx.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	clear_screen(t_tools *tool)
{
  int	i;
  int	j;
  
  i = 1;
  j = 0;
  while (i != HEIGHT)
    {
      j = 1;
      while (j != HEIGHT)
	{
	  j++;
	  put_black_pixel(i, j, tool);
	}
      i++;
    }
  return (0);
}
