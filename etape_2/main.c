/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 18:16:02 2014 Jean Gravier
** Last update Sat Mar  8 19:00:56 2014 Fritsch harold
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
    ;//move_up(node, node->player);
  else if (keystates[SDLK_DOWN])
    ;//move_down(node, node->player);
}
t_character	*get_vilains(t_node *node)
{
  t_character	*vilains;
  size_t	i;
  size_t	*last_pos;

  i = 0;
  if ((last_pos = malloc(sizeof(size_t) * 2)) == NULL)
    exit_error("malloc error");
  last_pos[0] = 0;
  last_pos[1] = 0;
  if ((vilains = malloc(sizeof(t_character) * node->nb_vilains)) == NULL)
    exit_error("malloc error");
  while (i < node->nb_vilains)
    {
      last_pos = set_nposition(node->map, &vilains[i], 'm', last_pos);
      vilains[i].direction = LEFT;
      ++i;
    }
  return (vilains);
}

void		sdl_loop(t_node *node, t_character **vilains)
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
      move_ia(node, vilains);
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
  SDL_WM_SetCaption("Super Expendablos Deluxe edifion", NULL);
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
  t_character	*vilains;
  t_node	s;

  surface = NULL;
  if (argc > 1)
    {
      init(&s, &map, &player, surface);
      feed_map(s.map, argv[1]);
      set_position(s.map, s.player, 'i');
      s.nb_vilains = get_block_nb(s.map, 'm');
      s.surface = sdl_init(s.map, s.surface);
      draw_map(s.map, s.surface);
      vilains = get_vilains(&s);
      sdl_loop(&s, &vilains);
      SDL_Quit();
    }
  return (0);
}
