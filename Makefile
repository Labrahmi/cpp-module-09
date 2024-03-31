# Makefile
SRCS = main.cpp

OBJS := $(SRCS:.cpp=.o)
OBJS := $(addprefix obj/, $(OBJS))

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -rf obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re