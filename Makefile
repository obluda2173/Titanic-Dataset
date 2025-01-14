NAME        = titanic

CXX         = @c++
CXXFLAGS    = -std=c++17 -Wall -Wextra -Werror -g

SRCDIR      = src
OBJDIR      = obj
INC         = -Iinc

SRC         = $(wildcard $(SRCDIR)/*.cpp)
OBJ         = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Colors for output
RED         := \033[1;31m
GREEN       := \033[1;32m
BLUE        := \033[1;34m
RESET       := \033[0m

# Default target
all: $(NAME)

# Link objects to create the executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INC) $^ -o $@
	@echo "$(GREEN)Built successfully$(RESET)"

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Ensure the object directory exists
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean object files
clean:
	@echo "$(BLUE)Cleaning objects$(RESET)"
	@rm -fr $(OBJDIR)

# Clean object files and the executable
fclean: clean
	@echo "$(BLUE)Cleaning executable$(RESET)"
	@rm -f processed_data.csv && rm -f *.png
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Python rule (optional)
py:
	@python3 $(SRCDIR)/graphs.py

.PHONY: all clean fclean re py
