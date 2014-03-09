/*
** main.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 16:10:45 2014 Jean Gravier
** Last update Sun Mar  9 21:34:52 2014 Fritsch harold
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "epikong.h"

void		get_vilains(t_node *node)
{
  size_t	i;
  size_t	*last_pos;

  i = 0;
  if ((last_pos = malloc(sizeof(size_t) * 2)) == NULL)
    exit_error("malloc error");
  last_pos[0] = 0;
  last_pos[1] = 0;
  if ((node->vilains = malloc(sizeof(t_character *) * node->nb_vilains))
      == NULL)
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
  int		i;
  int		stop;
  SDL_Event	event;
  Uint8		*keystates;
  int		k;

  stop = 0;
  keystates = SDL_GetKeyState(NULL);
  while (!stop)
    {
      i = -1;
      while (++i < 4)
	move_ia(node);
      while (i > 0 && !stop)
	{
	  SDL_WaitEvent(&event);
	  usleep(25000);
	  fall(node);
	  if (event.type == SDL_QUIT)
	    stop = 1;
	  else if ((event.type == SDL_KEYDOWN) &&
		   (((k = event.key.keysym.sym) == SDLK_UP) ||
		    (k == SDLK_DOWN) || (k == SDLK_LEFT) ||
		    (k == SDLK_RIGHT) || (k == SDLK_ESCAPE) ||
		    (k == SDLK_RETURN)))
	    {
	      check_keys(node, keystates, &stop, &event);
	      --i;
	    }
	}
    }
}

SDL_Surface	*sdl_init(t_map *map, SDL_Surface *surface)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
    {
      fprintf(stderr, "Erreur initialisation SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  surface = SDL_SetVideoMode(map->width * BLOCK_SIZE, map->height *
			     BLOCK_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  draw_image(surface, "../data/contents/backgrounds/bg1.png", 0, 0);
  SDL_WM_SetCaption("Super Expendablos Deluxe Edifion", NULL);
  return (surface);
}

void		init(t_node *s, t_map *map, t_character *p, SDL_Surface *sur)
{
  s->map = map;
  p->in_air = FALSE;
  s->player = p;
  s->surface  = sur;
  s->musique[GAME] = Mix_LoadMUS(SOUND_GAME);
}

int		main()
{
  SDL_Surface	*surface;
  t_map		map;
  t_character	player;
  t_node	s;

  surface = NULL;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    exit_error(Mix_GetError());
  menu(surface, &map);
  init(&s, &map, &player, surface);
  feed_map(s.map, s.map->path);
  set_position(s.map, s.player, 'i');
  s.nb_vilains = get_block_nb(s.map, 'm');
  s.surface = sdl_init(s.map, s.surface);
  draw_map(s.map, s.surface);
  get_vilains(&s);
  Mix_PlayMusic(s.musique[GAME], -1);
  sdl_loop(&s);
  Mix_FreeMusic(s.musique[GAME]);
  Mix_CloseAudio();
  SDL_Quit();
  return (0);
}
