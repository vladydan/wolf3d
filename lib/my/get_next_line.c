/*
** get_next_line.c for get_next_line in /home/danilo_d/rendu/MUL_2014_fdf
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Nov  26 08:38:20 2014 Danilov Dimitri
** Last update Sun Dec  7 22:07:24 2014 Danilov Dimitri
*/

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include "get_next_line.h"


char            *init_buffer(char *buffer, int j, int len)
{
  while (j != (len + BUFFER_SIZE + 1))
    {
      buffer[j] = '\0';
      j = j + 1;
    }
  return (buffer);
}


int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    exit(1);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char		*remalloc(char *str)
{
  char		*str2;
  int		i;

  i = 0;
  str2 = malloc(my_strlen(str) + BUFFER_SIZE + 1);
  if (str2 == NULL)
    exit(1);
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i = i + 1;
    }
  str2 = init_buffer(str2, i, my_strlen(str));
  free(str);
  return (str2);
}

char		*my_strcpy(char *dest, char *src, int *i, int *j)
{
  while (src[*j] == '\n')
    *j = *j + 1;
  while (src[*j] != '\0' && src[*j] != '\n')
    {
      dest[*i] = src[*j];
      *i = *i + 1;
      *j = *j + 1;
    }
  dest = remalloc(dest);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static int	ret = 1;
  static int	j = BUFFER_SIZE;
  static char	buffer[BUFFER_SIZE + 1];
  char          *str;
  int           i;

  ret = 1;
  i = 0;
  if (((str = malloc(BUFFER_SIZE + 1)) == NULL))
    return (NULL);
  str = init_buffer(str, 0, 0);
  while (ret > 0 && buffer[j] != '\n')
    if (j >= ret && buffer[j] == '\0')
      {
	init_buffer(buffer, 0, 0);
	if (((ret = read(fd, buffer, BUFFER_SIZE)) <= 0) && my_strlen(str) <= 0)
	  return (NULL);
	j = 0;
      }
    else if (ret > 0)
      if ((str = my_strcpy(str, buffer, &i, &j)) == NULL)
	return (NULL);
  j = j + 1;
  return (str);
}
