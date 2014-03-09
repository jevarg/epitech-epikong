/*
** draw_all_sprites.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 01:07:21 2014 Jean Gravier
** Last update Sun Mar  9 22:11:07 2014 Fritsch harold
*/

#include "epikong.h"

void		draw_all_sprites(SDL_Surface *surface)
{
  draw_image(surface, "../data/map/door-enter.png",
	     BLOCK_SIZE * 0, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/door-out.png",
	     BLOCK_SIZE * 1, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/ladder.png",
	     BLOCK_SIZE * 2, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall1.png",
	     BLOCK_SIZE * 3, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall2.png",
	     BLOCK_SIZE * 4, BLOCK_SIZE * 0);
  draw_image(surface, "../data/map/wall3.png",
	     BLOCK_SIZE * 5, BLOCK_SIZE * 0);
  draw_image(surface, "../data/characters/mechant1-right.png",
	     BLOCK_SIZE * 0, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/mechant2-left.png",
	     BLOCK_SIZE * 1, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/mechant3-right.png",
	     BLOCK_SIZE * 2, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso1-left.png",
	     BLOCK_SIZE * 3, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso2-right.png",
	     BLOCK_SIZE * 4, BLOCK_SIZE * 1);
  draw_image(surface, "../data/characters/perso3-left.png",
	     BLOCK_SIZE * 5, BLOCK_SIZE * 1);
}
