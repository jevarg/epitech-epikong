/*
** menu.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 21:45:53 2014 Jean Gravier
** Last update Sun Mar  9 20:40:35 2014 Jean Gravier
*/

#include <unistd.h>
#include "epikong.h"

void		menu_render_image(SDL_Surface *surface, char *path, int x, int y)
{
  if (x > 0)
    draw_image(surface, path, x, y);
  else
    draw_image_menu_part(surface, path, x, y);
}

void		menu_rotate_left(SDL_Surface *surface, int *select)
{
  char		*maps[5];
  int		gap;
  int		x;

  x = (800 / 2) - (500 / 2);
  gap = x;
  maps[0] = "../data/contents/menu/thumb/map1.png";
  maps[1] = "../data/contents/menu/thumb/map2.png";
  maps[2] = "../data/contents/menu/thumb/map3.png";
  maps[3] = "../data/contents/menu/thumb/map4.png";
  maps[4] = "../data/contents/menu/thumb/map5.png";
  while (x > (-500))
    {
      x -= MENU_SPEED;
      draw_image_only(surface, "../data/map/backgrounds/bg.png", 0, 0);
      menu_render_image(surface, maps[*select], x, 150);
      if (*select - 1 < 0)
	menu_render_image(surface, maps[4], (x + gap + 500), 150);
      else
	menu_render_image(surface, maps[*select - 1], (x + gap + 500), 150);
      SDL_Flip(surface);
    }
  if (*select - 1 < 0)
    *select = 4;
  else
    *select = *select - 1;

}

void		menu_rotate_right(SDL_Surface *surface, int *select)
{
  char		*maps[5];
  int		gap;
  int		x;

  x = (800 / 2) - (500 / 2);
  gap = x;
  maps[0] = "../data/contents/menu/thumb/map1.png";
  maps[1] = "../data/contents/menu/thumb/map2.png";
  maps[2] = "../data/contents/menu/thumb/map3.png";
  maps[3] = "../data/contents/menu/thumb/map4.png";
  maps[4] = "../data/contents/menu/thumb/map5.png";
  while (x < 800)
    {
      x += MENU_SPEED;
      draw_image_only(surface, "../data/map/backgrounds/bg.png", 0, 0);
      draw_image_only(surface, maps[*select], x, 150);
      if (*select + 1 > 4)
	menu_render_image(surface, maps[0], (x - gap - 500), 150);
      else
	menu_render_image(surface, maps[*select + 1], (x - gap - 500), 150);
      SDL_Flip(surface);
    }
  if (*select + 1 > 4)
    *select = 0;
  else
    *select = *select + 1;
}

void		pause_menu(SDL_Surface *surface, t_map *map)
{
  int		stop;
  int		select;
  SDL_Event	event;

  stop = 0;
  select = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	stop = 1;
      else if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_ESCAPE)
	    stop = 1;
	  else if (event.key.keysym.sym == SDLK_LEFT)
	    menu_rotate_left(surface, &select);
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    menu_rotate_right(surface, &select);
	  else if (event.key.keysym.sym == SDLK_RETURN)
	    {
	      set_map(map, &select);
	      stop = 1;
	    }
	}
    }
}

void		menu(SDL_Surface *surface, t_map *map)
{
  Mix_Music	*music;

  surface = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  draw_image(surface, "../data/map/backgrounds/bg.png", 0, 0);
  draw_image(surface, "../data/contents/menu/thumb/map1.png", ((800 / 2) - (500 / 2)), 150);
  SDL_Flip(surface);
  music = Mix_LoadMUS(SOUND_MENU);
  Mix_PlayMusic(music, -1);
  pause_menu(surface, map);
  Mix_FreeMusic(music);
  SDL_FreeSurface(surface);
}
