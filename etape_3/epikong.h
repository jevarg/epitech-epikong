/*
** epikong.h for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_2
**
** Made by Jean Gravier
** Login   <gravie_j@epitech.net>
**
** Started on  Sun Mar  9 02:44:03 2014 Jean Gravier
** Last update Sun Mar  9 19:49:22 2014 Fritsch harold
*/

#ifndef EPIKONG_H_
# define EPIKONG_H_

# define BLOCK_SIZE (30)
# define FALL_SPEED (50000)
# define MENU_SPEED (45)
# define TRUE (1)
# define FALSE (0)
# define INVALID_MAP_MSG "Invalid map"
# define SPRITE_BACKGROUND "../data/contents/backgrounds/bg1.png"
# define SPRITE_WALL "../data/contents/world/wall4.png"
# define SPRITE_LADDER "../data/contents/world/ladder.png"
# define SPRITE_VILAIN_LEFT "../data/characters/vilain1/mechant1-left.png"
# define SPRITE_VILAIN_RIGHT "../data/characters/vilain1/mechant1-right.png"
# define SPRITE_OPEN_DOOR "../data/contents/world/car-out.png"
# define SPRITE_CLOSE_DOOR "../data/contents/world/in-helicrash.png"
# define SPRITE_PLAYER_LEFT "../data/characters/perso1/perso1-left.png"
# define SPRITE_PLAYER_RIGHT "../data/characters/perso1/perso1-right.png"

# define SOUND_MENU "../data/contents/sound/HorseSteppin.ogg"
# define SOUND_GAME "../data/contents/sound/Static.ogg"
# define MENU (1)
# define GAME (0)


# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>

typedef enum e_direction
  {
    LEFT,
    RIGHT
  }t_direction;

typedef enum e_type
  {
    PLAYER,
    VILAIN
  }t_type;

typedef struct	s_map
{
  size_t	width;
  size_t	height;
  char		*path;
  char		*bg_path;
  char		**map;
}		t_map;

typedef struct	s_character
{
  int		live;
  t_type	type;
  size_t	x;
  size_t	y;
  t_direction	direction;
  char		in_air;
}		t_character;

typedef struct	s_node
{
  Mix_Music	*musique[2];
  t_map		*map;
  t_character	*player;
  t_character	**vilains;
  size_t	nb_vilains;
  SDL_Surface	*surface;
}		t_node;

/*
** map.c
*/

void		check_map(t_map *);
void		feed_map(t_map *, char *);
char		*correct_line(char *);
size_t		get_block_nb(t_map *, char);

/*
** error.c
*/

void		exit_error(char *);

/*
** draw_image.c
*/

void		draw_image(SDL_Surface *, char *, int, int);
void		draw_image_menu_part(SDL_Surface *, char *, int, int);
void		draw_image_only(SDL_Surface *, char *, int, int);
SDL_Surface	*get_image(char *);
void		blit_part(SDL_Surface *, SDL_Rect *, char *);

/*
** draw_map.c
*/

void		draw_map(t_map *, SDL_Surface *);

/*
** character.c
*/

void		set_position(t_map *, t_character *, char);
size_t		*set_nposition(t_map *, t_character *, char, size_t[2]);
void		set_char_type(t_character *, char, int, int);

/*
** ia.c
*/

void		move_ia(t_node *);

/*
** check.c
*/

int		valid(t_map *, size_t, size_t);
int		is_walkable(t_map *, size_t, size_t);
SDL_Surface	*get_old_block(t_node *, size_t, size_t, t_character *);
void		check_keys(t_node *, Uint8 *, int *, SDL_Event *);

/*
** movement.c
*/

void		fill_rect(t_character *, SDL_Rect *);
int		move_left(t_node *, t_character *);
int		move_right(t_node *, t_character *);
int		move_up(t_node *, t_character *);
int		move_down(t_node *, t_character *);

/*
** air.c
*/

void		jump_left(t_node *);
void		jump_right(t_node *);
void		jump(t_node *);
char		first_cell_fall(t_node *);
void		fall(t_node *);

/*
** ladder.c
*/

int		ladder_up(t_node *);
void		ladder_down(t_node *);
char		landing(t_node *);

#endif /* !EPIKONG_H_ */
