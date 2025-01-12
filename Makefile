NAME		=	titanic

# compiler and flags
CXX			=	@c++
CXXFLAGS	=	-std=c++11 -Wall -Wextra -Werror -g -I/usr/include/python3.x

# sources and objects
SRC			=	$(wildcard *.cpp)
OBJ			=	$(SRC:.cpp=.o)

# colors for output
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
BLUE		:=	\033[1;34m
RESET		:=	\033[0m

# default target
all: $(NAME)

# link objects to create executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)built successfully$(RESET)"

# clean object files
clean:
	@echo "$(BLUE)cleaning objects$(RESET)"
	@rm -f $(OBJ)

# clean executable and object files
fclean: clean
	@echo "$(BLUE)cleaning executable$(RESET)"
	@rm -f $(NAME)

# rebuild
re: fclean all

# declare targets as not files
.PHONY: all clean fclean re