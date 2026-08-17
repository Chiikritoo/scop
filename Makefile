NAME		= scop

CXX			?= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17 -MMD -MP

SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin
INC_DIR		= include

SRCS		= $(shell find $(SRC_DIR) -name '*.cpp')
OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

INCLUDES	= -I$(INC_DIR)

BIN			= $(BIN_DIR)/$(NAME)

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(BIN)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
