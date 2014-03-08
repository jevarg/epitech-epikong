/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 21:22:45 2014 Jean Gravier
** Last update Sat Mar  8 01:54:42 2014 Jean Gravier
*/

#include <stdio.h>
#include <stdlib.h>
#include "epikong.h"

void		pause()
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
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  stop = 1;
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

int		main(int argc, char *argv[])
{
  SDL_Surface	*surface;
  t_map		map;

  surface = NULL;
  if (argc > 1)
    {
      feed_map(&map, argv[1]);
      surface = sdl_init(&map, surface);
      draw_map(&map, surface);
      pause();
      SDL_Quit();
    }
  return (0);
}
