##
## Makefile for rush in /home/gravie_j/Documents/projets/T2Rush1/etape_1
##
## Made by Jean Gravier
## Login   <gravie_j@epitech.net>
##
## Started on  Fri Mar  7 21:36:25 2014 Jean Gravier
## Last update Sat Mar  8 13:07:44 2014 Brieuc de La Fouchardiere
##

CC=		gcc

RM=		rm -f

NAME=		epikong

SRCS=		main.c \
		draw_map.c \
		draw_image.c \
		draw_all_sprites.c \
		map.c \
		error.c \

OBJS=		$(SRCS:.c=.o)

CFLAGS +=	-Wall -Wextra

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lSDL -lSDL_image

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
