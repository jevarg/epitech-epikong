/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 13:03:57 2014 Jean Gravier
** Last update Sat Mar  8 13:26:36 2014 Jean Gravier
*/

#include <stdio.h>
#include <stdlib.h>
#include "epikong.h"

void		pause(t_node *node)
{
  int		stop;
  SDL_Event	event;

  stop = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	stop = 1;
      else if (SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    stop = 1;
	  else if (event.key.keysym.sym == SDLK_LEFT)
	    move_left(node);
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    move_right(node);
	}
    }
}

SDL_Surface	*sdl_init(t_map *map, SDL_Surface *surface)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur initialisation SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  surface = SDL_SetVideoMode(map->width * BLOCK_SIZE, map->height * BLOCK_SIZE, 32, SDL_HWSURFACE);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 40, 40, 40));
  SDL_Flip(surface);
  return (surface);
}

void		init(t_node *s, t_map *map, t_character *c, SDL_Surface *sur)
{
  s->map = map;
  s->character = c;
  s->surface  = sur;
}

int		main(int argc, char *argv[])
{
  SDL_Surface	*surface;
  t_map		map;
  t_character	character;
  t_node	s;

  surface = NULL;
  if (argc > 1)
    {
      init(&s, &map, &character, surface);
      feed_map(s.map, argv[1]);
      s.surface = sdl_init(s.map, s.surface);
      SDL_WM_SetCaption("Super Expendablos Deluxe edifion", NULL);
      set_position(s.map, s.character, 'i');
      draw_map(s.map, s.surface);
      pause(&s);
      SDL_Quit();
    }
  return (0);
}
