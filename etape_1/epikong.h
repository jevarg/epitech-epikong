/*
** epikong.h for  in /home/fritsc_h/projets/T2Rush1/etape_1
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Fri Mar  7 21:39:40 2014 Fritsch harold
** Last update Fri Mar  7 23:59:39 2014 Jean Gravier
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_
# define BLOCK_SIZE 30

#include <SDL/SDL.h>

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		**map;
}		t_map;

/*
** map.c
*/

void		feed_map(t_map *, char *);

/*
** draw_image.c
*/

void		draw_image(SDL_Surface *, char *, int, int);

/*
** draw_map.c
*/

void		draw_map(SDL_Surface *);

#endif /* !EPIKONG_H_ */
