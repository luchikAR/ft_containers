NAME     = ft_containers

SRCS_FT		= ft_main.cpp
SRCS_STD	= std_main.cpp

hpp		=  include/vector.hpp

OBJS     = $(SRCS_FT:.cpp=.o)

OBJS_STD = $(SRCS_STD:.cpp=.o)

CXX      = clang++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(hpp)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "\033[0m"

std: $(OBJS_STD) $(hpp)
	@$(CXX) $(OBJS_STD) -o $@

%.o: %.cpp
	@printf "\x1b[32m"
	$(CXX) $(CXXFLAGS) -o $@ -c $<
	@printf "\033[0m"

clean:
	@rm -f $(OBJS) $(OBJS_STD)
	@echo "\033[31m [INFO] Objects removed! \033[0m"

fclean: clean
	@rm -f $(NAME) ./std
	@echo "\033[31m [INFO] $(NAME) removed! \033[0m"

re:     fclean all

.PHONY: all clean fclean format re
