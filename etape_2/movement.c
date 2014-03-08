/*
** movement.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 12:26:37 2014 Jean Gravier
** Last update Sat Mar  8 18:14:54 2014 Jean Gravier
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

int		is_walkable(t_map *map, size_t x, size_t y)
{
  if ((x >= map->width && y >= map->height)
      && (x < 0 && y < 0))
    return (0);
  if (map->map[y][x] == 'w')
    return (1);
  else if (map->map[y][x] == 's')
    return (1);
  return (0);
}

SDL_Surface	*get_old_block(t_node *node, size_t x, size_t y, t_character *character)
{
  if (node->map->map[y][x] == 's')
    return (get_image(SPRITE_LADDER));
  else if (node->map->map[y][x] == 'i')
    return (get_image(SPRITE_CLOSE_DOOR));
  else if (node->map->map[y][x] == 'o')
    return (get_image(SPRITE_OPEN_DOOR));
  if (character->type == PLAYER)
    {
      if (node->map->map[y][x] == 'm')
	return (get_image(SPRITE_VILAIN_LEFT));
    }
  else if (character->type == VILAIN)
    if (character->x == node->player->x
	&& character->y == node->player->y)
      return (get_image(SPRITE_PLAYER_LEFT));
  return (NULL);
}

int		move_left(t_node *node, t_character *character)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((character->x - 1) > 0
      && valid(node->map, character->x - 1, character->y))
    {
      if (character->type == VILAIN
	  && !is_walkable(node->map, character->x - 1, character->y + 1))
	return (0);
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->x -= 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      if (character->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_LEFT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
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
      if (character->type == VILAIN
	  && !is_walkable(node->map, character->x + 1, character->y + 1))
	return (0);
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->x += 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_RIGHT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      else if (character->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_RIGHT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}

int		move_up(t_node *node, t_character *character)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((character->y - 1) > 0
      && valid(node->map, character->x, character->y - 1))
    {
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->y -= 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}

int		move_down(t_node *node, t_character *character)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((character->y + 1) > 0
      && valid(node->map, character->x, character->y + 1))
    {
      rect.x = character->x * BLOCK_SIZE;
      rect.y = character->y * BLOCK_SIZE;
      rect.w = BLOCK_SIZE;
      rect.h = BLOCK_SIZE;
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->y += 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT, character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}
