/*
** error.c for  in /home/fritsc_h/projets/T2Rush1/etape_1
**
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
**
** Started on  Sat Mar  8 00:57:12 2014 Fritsch harold
** Last update Sun Mar  9 18:47:10 2014 Brieuc de La Fouchardiere
*/

#include <stdio.h>
#include <stdlib.h>

void	exit_error(const char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(EXIT_FAILURE);
}
