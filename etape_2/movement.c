/*
** movement.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 20:52:30 2014 Jean Gravier
** Last update Sun Mar  9 01:15:22 2014 Fritsch harold
*/

#include "epikong.h"

void		fill_rect(t_character *character, SDL_Rect *rect)
{
  rect->x = character->x * BLOCK_SIZE;
  rect->y = character->y * BLOCK_SIZE;
  rect->w = BLOCK_SIZE;
  rect->h = BLOCK_SIZE;
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
      fill_rect(character, &rect);
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format,
						    40, 40, 40));
      if ((old = get_old_block(node, character->x--, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      if (character->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_LEFT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      if ((character->type == PLAYER) && character->in_air == FALSE)
	fall(node);
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
      fill_rect(character, &rect);
      SDL_FillRect(node->surface, &rect,
		   SDL_MapRGB(node->surface->format, 40, 40, 40));
      if ((old = get_old_block(node, character->x++, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_RIGHT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      else if (character->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_RIGHT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      if ((character->type == PLAYER) && (character->in_air == FALSE))
	fall(node);
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
      fill_rect(character, &rect);
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format,
						    40, 40, 40));
      if ((old = get_old_block(node, character->x,
			       character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->y -= 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
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
      fill_rect(character, &rect);
      SDL_FillRect(node->surface, &rect, SDL_MapRGB(node->surface->format,
						    40, 40, 40));
      if ((old = get_old_block(node, character->x, character->y, character)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      character->y += 1;
      if (character->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   character->x * BLOCK_SIZE, character->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}
