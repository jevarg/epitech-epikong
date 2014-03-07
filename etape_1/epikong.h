/*
** epikong.h for  in /home/fritsc_h/projets/T2Rush1/etape_1
** 
** Made by Fritsch harold
** Login   <fritsc_h@epitech.net>
** 
** Started on  Fri Mar  7 21:39:40 2014 Fritsch harold
** Last update Fri Mar  7 23:10:46 2014 Fritsch harold
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		**map;
}		t_map;

/*
** map.c
*/

void		feed_map(t_map *, char *);

#endif /* !EPIKONG_H_ */
