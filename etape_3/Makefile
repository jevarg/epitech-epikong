##
## Makefile for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_3
##
## Made by Jean Gravier
## Login   <gravie_j@epitech.net>
##
## Started on  Sun Mar  9 22:35:54 2014 Jean Gravier
## Last update Sun Mar  9 23:00:29 2014 Jean Gravier
##

CC=		gcc

RM=		rm -f

NAME=		epikong

SRCS=		main.c \
		menu.c \
		draw_map.c \
		draw_image.c \
		draw_all_sprites.c \
		character.c \
		movement.c \
		ia.c \
		map.c \
		error.c \
		key.c \
		air.c \
		ladder.c \
		dead.c \
		win.c \
		check.c \
		block.c \
		menu_maps.c

OBJS=		$(SRCS:.c=.o)

CFLAGS +=	-Wall -Wextra

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lSDL -lSDL_image -lSDL_mixer

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
