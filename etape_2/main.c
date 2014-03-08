/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 13:03:57 2014 Jean Gravier
** Last update Sat Mar  8 16:41:24 2014 Fritsch harold
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "epikong.h"

void		check_keys(t_node *node, Uint8 *keystates, int *stop)
{
  if (keystates[SDLK_ESCAPE])
    *stop = 1;
  else if (keystates[SDLK_LEFT] && keystates[SDLK_UP])
    puts("jump left");//jump_left(node);
  else if (keystates[SDLK_RIGHT] && keystates[SDLK_UP])
    puts("jump right");//jump_right(node);
  else if (keystates[SDLK_LEFT])
    move_left(node);
  else if (keystates[SDLK_RIGHT])
    move_right(node);
  else if (keystates[SDLK_UP])
    puts("up");//move_up(node);
  else if (keystates[SDLK_DOWN])
    puts("down");//move_down(node);
}

void		sdl_loop(t_node *node)
{
  int		stop;
  SDL_Event	event;
  Uint8		*keystates;

  stop = 0;
  keystates = SDL_GetKeyState(NULL);
  while (!stop)
    {
      SDL_PollEvent(&event);
      usleep(100000);
      if (event.type == SDL_QUIT)
	stop = 1;
      else if (event.type == SDL_KEYDOWN)
	{
	  check_keys(node, keystates, &stop);
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
      sdl_loop(&s);
      SDL_Quit();
    }
  return (0);
}
