
SRCS = srcs/main.c srcs/display_map.c srcs/initialise_manager.c srcs/parsing.c srcs/move.c srcs/test_map.c
NAME = so_long
OBJS = $(SRCS:.c=.o)
GNL = get_next_line/gnl
CC = gcc


all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C get_next_line
	$(CC) $(OBJS) $(GNL) -lmlx -framework OpenGL -framework AppKit -ggdb3 -fsanitize=address -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c -I./includes $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C get_next_line
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re