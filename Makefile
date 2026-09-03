NAME = npuzzle
CC = c++
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I src

SRCS = src/test.cpp \
		src/main.cpp src/parse.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
