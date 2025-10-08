CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CMLX = -lmlx -lXext -lX11

SRC = 

SRCB = 


OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)

BONUS = .bns

NAME = cub3D
RM = rm -f

all: libft_rule $(NAME)

bonus: libft_rule $(BONUS)

$(BONUS): $(OBJB)
	@touch $(BONUS)
	$(CC) $(OBJB) $(CMLX) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CMLX) -L$(LIBFT_DIR) -lft -o $(NAME)

libft_rule:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ) $(OBJB)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(BONUS)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	

re: fclean all

.SECONDARY: $(OBJ) $(OBJB)
.PHONY: all clean fclean re bonus
