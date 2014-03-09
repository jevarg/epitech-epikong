/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 20:52:41 2014 Jean Gravier
** Last update Sun Mar  9 01:28:58 2014 Jean Gravier
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
    jump_left(node);
  else if (keystates[SDLK_RIGHT] && keystates[SDLK_UP])
    jump_right(node);
  else if (keystates[SDLK_LEFT])
    move_left(node, node->player);
  else if (keystates[SDLK_RIGHT])
    move_right(node, node->player);
  else if (keystates[SDLK_UP])
    jump(node);
  else if (keystates[SDLK_DOWN])
    ;//move_down(node, node->player);
}

void		get_vilains(t_node *node)
{
  size_t	i;
  size_t	*last_pos;

  i = 0;
  if ((last_pos = malloc(sizeof(size_t) * 2)) == NULL)
    exit_error("malloc error");
  last_pos[0] = 0;
  last_pos[1] = 0;
  if ((node->vilains = malloc(sizeof(t_character *) * node->nb_vilains)) == NULL)
    exit_error("malloc error");
  while (i < node->nb_vilains)
    {
      if ((node->vilains[i] = malloc(sizeof(t_character))) == NULL)
	exit_error("malloc error");
      last_pos = set_nposition(node->map, node->vilains[i], 'm', last_pos);
      node->vilains[i]->direction = LEFT;
      ++i;
    }
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
      usleep(50000);
      move_ia(node);
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
  SDL_Surface	*background;
  SDL_Rect	rect;

  background = get_image("../data/map/backgrounds/bg1.png");
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur initialisation SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  surface = SDL_SetVideoMode(map->width * BLOCK_SIZE, map->height * BLOCK_SIZE, 32, SDL_HWSURFACE);
  rect.x = 0;
  rect.y = 0;
  rect.w = surface->w;
  rect.h = surface->h;
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 40, 40, 40));
  //SDL_BlitSurface(background, NULL, surface, &rect);
  SDL_Flip(surface);
  SDL_WM_SetCaption("Super Expendablos Deluxe Edifion", NULL);
  return (surface);
}

void		init(t_node *s, t_map *map, t_character *p, SDL_Surface *sur)
{
  s->map = map;
  s->player = p;
  s->surface  = sur;
}

int		main(int argc, char **argv)
{
  SDL_Surface	*surface;
  t_map		map;
  t_character	player;
  t_node	s;

  surface = NULL;
  //menu(surface, &map);
  init(&s, &map, &player, surface);
  feed_map(s.map, "test.map");
  set_position(s.map, s.player, 'i');
  s.nb_vilains = get_block_nb(s.map, 'm');
  s.surface = sdl_init(s.map, s.surface);
  draw_map(s.map, s.surface);
  get_vilains(&s);
  sdl_loop(&s);
  SDL_Quit();
  return (0);
}
