/*
** movement.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 12:26:37 2014 Jean Gravier
** Last update Sat Mar  8 15:57:34 2014 Jean Gravier
*/

#include "epikong.h"

int		valid(t_map *map, size_t x, size_t y)
{
  if ((x >= map->width && y >= map->height)
      && (x < 0 && y < 0))
    return (0);
  if (map->map[y][x] != 'w')
    return (1);
  return (0);
}

SDL_Surface	*get_old_block(t_node *node, size_t x, size_t y)
{
  if (node->map->map[y][x] == 's')
    return (get_image(SPRITE_LADDER));
  else if (node->map->map[y][x] == 'i')
    return (get_image(SPRITE_CLOSE_DOOR));
  else if (node->map->map[y][x] == 'o')
    return (get_image(SPRITE_OPEN_DOOR));
  else if (node->map->map[y][x] == 'm')
    return (get_image(SPRITE_MONSTER));
  return (NULL);
}

int		move_left(t_node *node, t_character *character)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((character->x - 1) > 0
      && valid(node->map, character->x - 1, character->y))
    {
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->x -= 1;
      draw_image(node->surface, SPRITE_PLAYER_LEFT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}

int		move_right(t_node *node, t_character *character)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((character->x + 1) < node->map->width
      && valid(node->map, character->x + 1, character->y))
    {
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->x += 1;
      draw_image(node->surface, SPRITE_PLAYER_RIGHT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}
