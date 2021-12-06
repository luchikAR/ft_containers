NAME     = ft_containers

SRCS_FT		= ft_main.cpp
SRCS_STD	= speed_test_vector.cpp

hpp		=  include/vector.hpp include/stack.hpp include/map.hpp

OBJS     = $(SRCS_FT:.cpp=.o)

OBJS_STD = $(SRCS_STD:.cpp=.o)

CXX      = clang++
CXXFLAGS = -g -std=c++98 -Wall -Werror -Wextra

# ft_main - test ft::vector<int>
all: $(NAME)

$(NAME): $(OBJS) $(hpp)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "\033[0m"

# speed_test_vector - test speed std::vector
speed: $(OBJS_STD) $(hpp)
	@$(CXX) $(OBJS_STD) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "\033[0m"

clean:
	@rm -f $(OBJS) $(OBJS_STD)
	@echo "\033[31m [INFO] Objects removed! \033[0m"

fclean: clean
	@rm -f $(NAME) ./speed
	@echo "\033[31m [INFO] $(NAME) removed! \033[0m"

re:     fclean all

.PHONY: all clean fclean format re
