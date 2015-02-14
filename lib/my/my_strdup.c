/*
** my_strdup.c for strdup in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Dec 24 11:18:31 2014 Danilov Dimitri
** Last update Wed Dec 24 11:19:10 2014 Danilov Dimitri
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  while (src[i] != '\0')
    i = i + 1;
  dest = malloc(i);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
