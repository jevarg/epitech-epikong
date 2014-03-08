/*
** main.c for  in /home/fritsc_h/projets/T2Rush1/etape_2
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Sat Mar  8 16:43:49 2014 Fritsch harold
** Last update Sat Mar  8 16:46:10 2014 Fritsch harold
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

t_character	*get_vilains(t_map *map)
{
  size_t	i;
  size_t	nbvilains;
  t_character	*vilains;

  i = 0;
  nbvilains = get_block_nb(map, 'm');
  if ((vilains = malloc(sizeof(t_character) * nbvilains)) == NULL)
    exit_error("malloc error");
  return (vilains);
}

void		sdl_loop(t_node *node, t_character *vilains)
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
  SDL_WM_SetCaption("Super Expendablos Deluxe edifion", NULL);
  return (surface);
}

void		init(t_node *s, t_map *map, t_character *p, SDL_Surface *sur)
{
  s->map = map;
  s->player = p;
  s->surface  = sur;
  set_position(s->map, s->player, 'i');
}

int		main(int argc, char **argv)
{
  SDL_Surface	*surface;
  t_map		map;
  t_character	player;
  t_character	*vilains;
  t_node	s;
  size_t	nbvilains;

  surface = NULL;
  if (argc > 1)
    {
      init(&s, &map, &player, surface);
      feed_map(s.map, argv[1]);
      s.surface = sdl_init(s.map, s.surface);
      draw_map(s.map, s.surface);
      vilains = get_vilains(s.map);
      sdl_loop(&s, &vilains);
      SDL_Quit();
    }
  return (0);
}
