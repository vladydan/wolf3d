/*
** xmalloc.c for xmalloc in /home/danilo_d/rendu/MUL_2014_fdf/lib/my
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec  6 20:01:09 2014 Danilov Dimitri
** Last update Sat Dec  6 20:31:19 2014 Danilov Dimitri
*/

#include <stdlib.h>

void	*xmalloc(int nbr)
{
  void	*ret;

  ret = malloc(nbr);
  if (ret == NULL)
    {
      exit(2);
    }
  return (ret);
}
