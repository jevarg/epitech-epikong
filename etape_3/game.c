/*
** game.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 23:26:01 2014 Jean Gravier
** Last update Sun Mar  9 23:36:18 2014 Jean Gravier
*/

#include "epikong.h"

void		init_game(SDL_Surface *surface, t_character *player,
			  t_map *map, t_node *node)
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    exit_error(Mix_GetError());
  while (!map->stop)
    {
      menu(surface, map);
      init(node, map, player, surface);
      feed_map(node->map, node->map->path);
      set_position(node->map, node->player, 'i');
      node->nb_vilains = get_block_nb(node->map, 'm');
      node->surface = sdl_init(node->map, node->surface);
      draw_map(node->map, node->surface);
      get_vilains(node);
      Mix_PlayMusic(node->sounds[GAME], -1);
      sdl_loop(node);
      Mix_FreeMusic(node->sounds[GAME]);
      Mix_FreeMusic(node->sounds[KEY]);
    }
}
