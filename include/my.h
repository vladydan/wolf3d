/*
** my.h for my_h in /home/danilo_d/rendu/MUL_2014_wolf3d
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec 20 17:31:17 2014 Danilov Dimitri
** Last update Fri Jan  2 08:21:03 2015 Danilov Dimitri
*/

#ifndef MY_H_
# define MY_H_
# define HEIGHT 700
# define LENGHT 700
# define ECHAP  65307
# define S	115
# define D	100
# define Q	113
# define ARR_L	65361
# define ARR_R  65363
# define ARR_U	65362
# define Z	122
# define BACK	115
# define ARR_B	65364
# define R	114
# define F	102
# define SHIFT	65505
# define ERROR  "Error, no wall at borders.\n"

typedef struct	 s_mlx
{
  void		 *ptr;
  void		 *window;
}		 t_mlx;

typedef struct 	s_mini_map
{
  int	i;
  int	j;
  int	coord_x;
  int	coord_y;
}		t_mini_map;

typedef struct	s_image
{
  char		*data;
  void		*img;
  int		bpp;
  int		sizeline;
  int		endian;
  int		sx;
  int		sy;
}		t_image;

typedef struct  s_position
{
  int           x;
  int           y;
}		t_position;

typedef struct  s_move
{
  int		up;
  int		back;
  int		left;
  int		right;
  int		sprint;
  int		look_up;
  int		look_down;
}		t_move;

typedef struct	s_tools
{
  double	speed;
  int		pos_look;
  int		size_x;
  int		size_y;
  t_mlx		ml;
  t_image	mg;
  t_image	ground;
  t_image	menu;
  t_image	texture;
  t_image	sky;
  t_position    **tab_pos;
  t_move	move;
  int		**tab;
  int		taille_i;
  int		taille_j;
  int		i;
  double       	angle;
  double       	pos_x;
  double       	pos_y;
  double       	x1;
  double       	y1;
  double       	X;
  double       	Y;
  double       	k;
  double       	vx;
  double       	vy;
  int       	pos_mur_x;
  int		ok;
  int		pos_mur_y;
  int		size_of_wall;
  char		*arg;
}		t_tools;

typedef struct	s_init
{
  int		fd;
  int		i;
  int		j;
  char		*line;
  int		a;
  int		y;
  int		size;
}		t_init;

void		create_map(t_tools *tool);
int		my_getnbr(char *str, int *i);
int             gere_button(int button, int x, int y, t_tools *tool);
void		*xmalloc(int nbr);
void            str_to_tab(t_tools *tool, char * path, t_init *init);
void		draw_map(t_tools *tool);
int             zero(int *a, int *j);
int		my_putchar(char c);
int		my_putstr(char *str);
void            size_of_tab(t_tools *tool, char *path);
int             gere_key(int key , t_tools *tool);
int             gere_expose(t_tools *tool);
void		pos_look(int key, t_tools *tool);
void		rotate(int key, t_tools *tool);
void		move_up(int key, t_tools *tool);
void		wolf3d(t_tools *tool);
int		move_Z(int key, t_tools *tool);
void		map_creator(t_tools *tool);
int		move_S(int key, t_tools *tool);
int		put_black_pixel(int x , int y, t_tools *ptr);
int	        clear_screen(t_tools *tool);
int		gere_key2(int key, t_tools *tool);
void		put_square(t_tools *tool, int coord_x, int coord_y, int flag);
int             gere_key_release(int key, t_tools *tool);
void		put_big_square(t_tools *tool, t_mini_map map, int flag);
int             segfault_protector(t_tools *tool);
int		move(t_tools *tool);
int		save(t_tools *tool);
int		pixel_copy(t_tools *ptr, int  x, int y, t_image texture);
char		*my_strdup(char *src);
int		put_white_pixel(t_tools *ptr, int  x, int y);
int		put_blue_pixel(t_tools *ptr, int  x, int y);
int		put_red_pixel(t_tools *ptr, int  x, int y);

#endif  /* !MY_H_ */
