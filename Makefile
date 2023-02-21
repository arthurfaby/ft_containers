NAME = ft_containers

all: $(NAME)

$(NAME):
	cd ft_containers-tester ; ./tester.sh ; ./benchmark.sh

clean:
	cd ft_containers-tester ; ./tester.sh clean
	

fclean: clean

re: fclean all

.PHONY: all clean fclean re
