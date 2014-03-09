/*
** menu.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sat Mar  8 21:45:53 2014 Jean Gravier
** Last update Sun Mar  9 16:09:08 2014 Jean Gravier
*/

#include <unistd.h>
#include "epikong.h"

void		menu_rotate_left(SDL_Surface *surface, int *select)
{
  char		maps[5];

  maps[0] = "";
  maps[1] = "";
  maps[2] = "";
  maps[3] = "";
  maps[4] = "";
  draw_image(surface, "../data/contents/menu/thumb/map1.png", ((800 / 2) - (500 / 2)), 150);
}

void		menu_rotate_right(SDL_Surface *surface, int *select)
{

}

char		*pause_menu(SDL_Surface *surface)
{
  int		stop;
  int		select;
  SDL_Event	event;

  stop = 0;
  while (!stop)
    {
      SDL_WaitEvent(&event);
      SDL_Delay(100);
      if (event.type == SDL_QUIT)
	stop = 1;
      else if (event.type == SDL_KEYDOWN)
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  stop = 1;
	else if (event.key.keysym.sym == SDLK_LEFT)
	  menu_rotate_left(surface, &select);
	else if (event.key.keysym.sym == SDLK_RIGHT)
	  menu_rotate_right(surface, &select);
	else if (event.key.keysym.sym == SDLK_RETURN)
	  return (select);
    }
}

void		menu(SDL_Surface *surface, t_map *map)
{
  SDL_Rect	rect;
  SDL_Surface	*background;

  rect.x = 0;
  rect.y = 0;
  rect.w = 800;
  rect.h = 600;
  surface = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  //SDL_FillRect(background, NULL, SDL_MapRGB(surface->format, 82, 82, 82));
  draw_image(surface, "../data/map/backgrounds/bg.png", 0, 0);
  draw_image(surface, "../data/contents/menu/thumb/map1.png", ((800 / 2) - (500 / 2)), 150);
  SDL_Flip(surface);
  pause_menu(map);
  SDL_FreeSurface(surface);
  //  SDL_Quit();
  //exit(1);
}
