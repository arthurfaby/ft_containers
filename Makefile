SRCS =	\
		main.cpp \
		tests/test_stack.cpp \
		tests/test_vector.cpp \
		\

OBJS = $(SRCS:.cpp=.o)

NAME = ft_containers

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
INCS	= -I. -Icontainers

#ifeq ($(STACK), 1)
#	VAR = -D STACK=1
#else
#	VAR = -D STACK=0
#endif

all: $(NAME)

.cpp.o:
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(INCS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -f std_tests ft_tests

re: fclean all

.PHONY: all clean fclean re
