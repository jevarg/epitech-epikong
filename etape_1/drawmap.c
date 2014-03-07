/*
** drawmap.c for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Fri Mar  7 20:58:06 2014 Jean Gravier
** Last update Fri Mar  7 21:36:56 2014 Jean Gravier
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void		drawmap()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Erreur initialisation SDL: %s\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
  SDL_Quit();
}
