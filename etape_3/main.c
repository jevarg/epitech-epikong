/*
** main.c for  in /home/fritsc_h/projets/T2Rush1/etape_3
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Sun Mar  9 23:10:17 2014 Fritsch harold
** Last update Sun Mar  9 23:35:48 2014 Jean Gravier
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
      node->vilains[i]->type = VILAIN;
      ++i;
    }
}

void		sdl_loop(t_node *node)
{
  int		i;
  SDL_Event	event;
  Uint8		*keystates;
  int		k;

  keystates = SDL_GetKeyState(NULL);
  while (!node->stop)
    {
      ia_cycle(node, &i);
      while (i > 0 && !node->stop)
	{
	  SDL_WaitEvent(&event);
	  usleep(25000);
	  fall(node);
       	  if (event.type == SDL_QUIT)
	    node->stop = 1;
	  else if ((event.type == P)
		   && (((k = event.key.keysym.sym) == U) || k == D || k == L ||
		       k == R || k == E || k == Q))
	    {
	      check_keys(node, keystates, &node->stop, &event);
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
  s->stop = 0;
  s->map = map;
  p->in_air = FALSE;
  p->key = FALSE;
  s->player = p;
  s->player->life = 3;
  s->surface  = sur;
  s->sounds[GAME] = Mix_LoadMUS(SOUND_GAME);
  s->sounds[KEY] = Mix_LoadMUS(SOUND_KEY);
}

int		main()
{
  SDL_Surface	*surface;
  t_map		map;
  t_character	player;
  t_node	s;

  surface = NULL;
  map.stop = 0;
  init_game(surface, &player, &map, &s);
  Mix_CloseAudio();
  SDL_Quit();
  return (0);
}
