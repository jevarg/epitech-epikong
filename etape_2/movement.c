/*
** movement.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 20:52:30 2014 Jean Gravier
** Last update Sun Mar  9 22:23:35 2014 Fritsch harold
*/

#include "epikong.h"

void		fill_rect(t_character *c, SDL_Rect *rect)
{
  rect->x = c->x * BLOCK_SIZE;
  rect->y = c->y * BLOCK_SIZE;
  rect->w = BLOCK_SIZE;
  rect->h = BLOCK_SIZE;
}

int		move_left(t_node *node, t_character *c)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((c->x - 1) > 0
      && valid(node->map, c->x - 1, c->y))
    {
      if (c->type == VILAIN && !is_walkable(node->map, c->x - 1, c->y + 1))
	return (0);
      fill_rect(c, &rect);
      blit_part(node->surface, &rect, "../data/contents/backgrounds/bg1.png");
      if ((old = get_old_block(node, c->x, c->y, c)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      SDL_FreeSurface(old);
      c->x -= 1;
      if (c->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      if (c->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_LEFT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      if ((c->type == PLAYER) && c->in_air == FALSE)
	fall(node);
      return (1);
    }
  return (0);
}

int		move_right(t_node *node, t_character *c)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((c->x + 1) < node->map->width
      && valid(node->map, c->x + 1, c->y))
    {
      if (c->type == VILAIN && !is_walkable(node->map, c->x + 1, c->y + 1))
	return (0);
      fill_rect(c, &rect);
      blit_part(node->surface, &rect, "../data/contents/backgrounds/bg1.png");
      if ((old = get_old_block(node, c->x, c->y, c)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      SDL_FreeSurface(old);
      c->x += 1;
      if (c->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_RIGHT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      else if (c->type == VILAIN)
	draw_image(node->surface, SPRITE_VILAIN_RIGHT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      if ((c->type == PLAYER) && (c->in_air == FALSE))
	fall(node);
      return (1);
    }
  return (0);
}

int		move_up(t_node *node, t_character *c)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((c->y - 1) > 0
      && valid(node->map, c->x, c->y - 1))
    {
      fill_rect(c, &rect);
      blit_part(node->surface, &rect, "../data/contents/backgrounds/bg1.png");
      if ((old = get_old_block(node, c->x, c->y, c)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      SDL_FreeSurface(old);
      c->y -= 1;
      if (c->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}

int		move_down(t_node *node, t_character *c)
{
  SDL_Rect	rect;
  SDL_Surface	*old;

  if ((c->y + 1) > 0
      && valid(node->map, c->x, c->y + 1))
    {
      fill_rect(c, &rect);
      blit_part(node->surface, &rect, "../data/contents/backgrounds/bg1.png");
      if ((old = get_old_block(node, c->x, c->y, c)))
	SDL_BlitSurface(old, NULL, node->surface, &rect);
      SDL_FreeSurface(old);
      c->y += 1;
      if (c->type == PLAYER)
	draw_image(node->surface, SPRITE_PLAYER_LEFT,
		   c->x * BLOCK_SIZE, c->y * BLOCK_SIZE);
      return (1);
    }
  return (0);
}
