CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CMLX = -lmlx -lXext -lX11

SRC = check_file_extension.c check_path_textures.c check.c \
	parse_color.c parse_map.c utils.c utils2.c utils3.c main.c free_game.c
	

OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)

NAME = cub3D
RM = rm -f

all: libft_rule $(NAME)


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CMLX) -L$(LIBFT_DIR) -lft -o $(NAME)

libft_rule:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re