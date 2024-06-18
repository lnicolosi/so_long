CC = gcc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = $(wildcard src/*.c)
GNL = $(wildcard Get_next_line/*.c)
PRINTF = $(wildcard Printf/*.c)
OBJ = $(SRC:.c=.o) $(GNL:.c=.o) $(PRINTF:.c=.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -g -Imlx -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all


.PHONY: all clean fclean re
