/*
** check.c for  in /home/fritsc_h/projets/T2Rush1/etape_2
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Sat Mar  8 23:32:23 2014 Fritsch harold
** Last update Sun Mar  9 20:33:22 2014 Jean Gravier
*/

#include "epikong.h"

int		valid(t_map *map, size_t x, size_t y)
{
  if (x >= map->width && y >= map->height)
    return (0);
  if (map->map[y][x] != 'w')
    return (1);
  return (0);
}

int		is_walkable(t_map *map, size_t x, size_t y)
{
  if (x >= map->width && y >= map->height)
    return (0);
  if (map->map[y][x] == 'w')
    return (1);
  else if (map->map[y][x] == 's')
    return (1);
  return (0);
}

SDL_Surface	*get_old_block(t_node *node, size_t x,
			       size_t y, t_character *character)
{
  if (node->map->map[y][x] == 's')
    return (get_image(SPRITE_LADDER));
  else if (node->map->map[y][x] == 'i')
    return (get_image(SPRITE_CLOSE_DOOR));
  else if (node->map->map[y][x] == 'o')
    return (get_image(SPRITE_OPEN_DOOR));
  if (character->type == VILAIN)
    if (character->x == node->player->x
	&& character->y == node->player->y)
      return (get_image(SPRITE_PLAYER_LEFT));
  return (NULL);
}

void		check_jump(t_node *node)
{
  if (ladder_up(node) == 0)
    jump(node);
}

void		check_keys(t_node *node, Uint8 *keystates, int *stop, SDL_Event *event)
{
  void		(*func_tab[SDLK_LEFT + 1])(t_node *);
  int		(*func_tab2[SDLK_LEFT + 1])(t_node *, t_character *);

  func_tab2[SDLK_LEFT] = &move_left;
  func_tab2[SDLK_RIGHT] = &move_right;
  func_tab[SDLK_UP] = &check_jump;
  func_tab[SDLK_DOWN] = &ladder_down;

  if (keystates[SDLK_LEFT] && keystates[SDLK_UP])
    jump_left(node);
  else if (keystates[SDLK_RIGHT] && keystates[SDLK_UP])
    jump_right(node);
  else if ((event->key.keysym.sym == SDLK_LEFT) ||
	   (event->key.keysym.sym == SDLK_RIGHT) ||
	   (event->key.keysym.sym == SDLK_DOWN) ||
	   (event->key.keysym.sym == SDLK_UP))
    {
      if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_DOWN)
	(*func_tab[event->key.keysym.sym])(node);
      else if (keystates[SDLK_LEFT] || keystates[SDLK_RIGHT])
	(*func_tab2[event->key.keysym.sym])(node, node->player);
    }
  if (keystates[SDLK_ESCAPE])
    *stop = 1;
}
