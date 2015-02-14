/*
** main.c for main in /home/danilo_d/rendu/MUL_2014_fdf/srcs
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sun Nov 16 14:27:29 2014 Dimitri Danilov
** Last update Mon Dec 29 13:04:03 2014 Danilov Dimitri
*/

#include <stdlib.h>
#include "mlx_int.h"
#include "mlx.h"
#include "my.h"
#include <stdio.h>

void		loading(t_tools *tool)
{
  mlx_string_put(tool->ml.ptr, tool->ml.window, 300, 300, 
		 0x00FFFFFF, "Chargement...");
  mlx_string_put(tool->ml.ptr, tool->ml.window, 200, 400, 
		 0x00FFFFFF, 
		 "Avancez avec ZQSD , SHIFT pour sprinter");
  mlx_string_put(tool->ml.ptr, tool->ml.window, 200, 500,
                 0x00FFFFFF, "Bougez la tete avec R et F");
  mlx_string_put(tool->ml.ptr, tool->ml.window, 200, 600,
                 0x00FFFFFF, "Ne me fais pas segfault :'(");
}

void		load_xpm(t_tools *tool)
{
  if ((tool->menu.img = mlx_xpm_file_to_image(tool->ml.ptr, "texture/menu.xpm",
					      &tool->menu.sx, 
					      &tool->menu.sy)) == NULL ||
      (tool->texture.img = mlx_xpm_file_to_image(tool->ml.ptr, "texture/wal.xpm",
						 &tool->texture.sx, 
						 &tool->menu.sy)) == NULL ||
       (tool->ground.img = mlx_xpm_file_to_image(tool->ml.ptr, 
					   "texture/ground.xpm", 
						&tool->ground.sx, 
						 &tool->ground.sy)) == NULL ||
	(tool->sky.img = mlx_xpm_file_to_image(tool->ml.ptr,
  					"texture/texture_sky.xpm", &tool->sky.
					     sx, &tool->sky.sy)) == NULL)
    {
      my_putstr("Impossible de trouvez une/des textures necessaire");
      exit(1);
    }      
  tool->menu.data = mlx_get_data_addr(tool->menu.img, &tool->menu.bpp,
                                      &tool->menu.sizeline, &tool->menu.endian);
  tool->texture.data = mlx_get_data_addr(tool->texture.img, &tool->texture.bpp,
  					 &tool->texture.sizeline, &tool->texture.endian);
  tool->ground.data = mlx_get_data_addr(tool->ground.img, &tool->ground.bpp,
  					&tool->ground.sizeline, &tool->ground.endian);
  tool->sky.data = mlx_get_data_addr(tool->sky.img, &tool->sky.bpp,
  				     &tool->sky.sizeline, &tool->sky.endian);
}

int		initilization(t_tools *tool, char *arg)
{
  tool->tab = xmalloc(sizeof(*tool->tab) * tool->size_y * + 10);
  tool->i = 0;
  while (tool->i < tool->size_y)
    {
      tool->tab[tool->i] = xmalloc(sizeof(**tool->tab) * tool->size_x + 10);
      tool->i++;
    }
  tool->arg = my_strdup(arg); 
  tool->pos_look = HEIGHT / 2;
  tool->angle = 0;
  tool->ok = 0;
  tool->speed = 0.01;
  tool->mg.img = mlx_new_image(tool->ml.ptr, HEIGHT, LENGHT); 
  tool->mg.data = mlx_get_data_addr(tool->mg.img, &tool->mg.bpp, 
			       &tool->mg.sizeline, &tool->mg.endian); 
  load_xpm(tool);
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->menu.img, 5, 5);
  return (0);
}

int		main(int argc, char **argv)
{
  t_tools	*tool;
  t_init        *init;

  if (argc != 2)
    return (0);
  tool = xmalloc(sizeof(*tool));
  init = xmalloc(sizeof(*init));
  size_of_tab(tool, argv[1]);
  if ((tool->ml.ptr = mlx_init()) == NULL ||
      (tool->ml.window = mlx_new_window(tool->ml.ptr, HEIGHT + 1 , LENGHT + 1,
					"wolf3d")) == NULL)
    return (-1);
  loading(tool);
  initilization(tool, argv[1]);
  str_to_tab(tool, argv[1], init);
  mlx_put_image_to_window(tool->ml.ptr, tool->ml.window, tool->menu.img, 5, 5);
  mlx_hook(tool->ml.window, ButtonPress, ButtonPressMask, &gere_button, tool);
  mlx_hook(tool->ml.window, KeyPress, KeyPressMask, &gere_key, tool);
  mlx_hook(tool->ml.window, KeyRelease, KeyReleaseMask, &gere_key_release, tool);
  mlx_loop_hook(tool->ml.ptr, move, tool);
  mlx_expose_hook(tool->ml.window, &gere_expose, tool);
  mlx_loop(tool->ml.ptr);
  return (0);
}
