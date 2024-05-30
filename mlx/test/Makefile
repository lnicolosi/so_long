
CFLAGS= -I../ -O3 -I..

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -framework OpenGL -framework AppKit

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
