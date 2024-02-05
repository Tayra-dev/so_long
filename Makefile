
SRCS = srcs/main.c srcs/display_map.c srcs/initialise_manager.c srcs/parsing.c srcs/move.c srcs/test_map.c srcs/test_map_utils.c
NAME = so_long
OBJS = $(SRCS:.c=.o)
GNL = gnl/gnl
PRINTF = ft_printf/libftprintf.a
CC = gcc


all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C gnl
	$(MAKE) -C ft_printf
	$(CC) $(OBJS) $(GNL) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -ggdb3 -fsanitize=address -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c -I./includes $< -o $@

clean :
	$(MAKE) clean -C gnl
	$(MAKE) clean -C ft_printf
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C gnl
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re