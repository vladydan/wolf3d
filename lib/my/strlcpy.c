/*
** strlcpy.c for strlcpy.c in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Fri Jan  2 08:43:07 2015 Danilov Dimitri
** Last update Fri Jan  2 08:56:05 2015 Danilov Dimitri
*/

#include <stdlib.h>
#include "my.h"

int             strlcpy(char *dst, const char *src, int siz)
{
  char		*d;
  char		*s;
  int		n;
  
  d = xmalloc(1);
  s = xmalloc(1);
  *d = *dst;
  *s = *src;
  n = siz;
  if (n != 0 && --n != 0)
    {
      while (--n != 0)
        {
          if ((*d++ = *s++) == 0)
            return (0);
        }
    }
  if (n == 0)
    {
      if (siz != 0)
        *d = '\0';
      while (*s++);
    }
  return (s - src - 1);
}
