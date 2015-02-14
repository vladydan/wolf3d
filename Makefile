##
## Makefile for makefile in /home/danilo_d/rendu/MUL_2014_fdf
## 
## Made by Dimitri Danilov
## Login   <danilo_d@epitech.net>
## 
## Started on  Sun Nov 16 14:20:35 2014 Dimitri Danilov
## Last update Sun Jan  4 15:07:30 2015 Dimitri Danilov
##

NAME	= wolf3d

LIBNAME	= libmy

LIBFO	= lib/my/

SRCSFO	= srcs/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)wolf3d.c \
	  $(SRCSFO)draw_map.c \
	  $(SRCSFO)segfault_protector.c \
	  $(SRCSFO)save.c \
	  $(SRCSFO)move_flag.c \
	  $(SRCSFO)map_creator.c \
	  $(SRCSFO)str_to_tab.c \
	  $(SRCSFO)gere_even.c

LIBSRCS	= $(LIBFO)my_get_nbr.c \
	  $(LIBFO)my_strdup.c \
	  $(LIBFO)strlcpy.c \
	  $(LIBFO)get_next_line.c \
	  $(LIBFO)put_pixel.c \
	  $(LIBFO)xmalloc.c \
	  $(LIBFO)my_display.c

OBJS	= $(SRCS:.c=.o)

LIBOBJS	= $(LIBSRCS:.c=.o)

CFLAGS	+= -I./include/ -Wall -Wextra

COMPIL  = -lmlx -L/usr/lib64 -lmy -Llib -L/usr/lib64/X11 -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(LIBNAME).a $(LIBOBJS)
	ranlib $(LIBNAME).a
	mv $(LIBNAME).a lib
	cc -o $(NAME) $(OBJS) $(CFLAGS) $(COMPIL)

clean:
	rm -f $(OBJS)
	rm -f $(LIBOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f lib/my/$(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
