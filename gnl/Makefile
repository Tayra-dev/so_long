SRCS = get_next_line.c get_next_line_utils.c
NAME = gnl
OBJS = $(SRCS:.c=.o)
CC = gcc


all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c -I./includes $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re