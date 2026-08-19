NAME		= scop

CXX			?= c++
CC			?= cc
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17 -MMD -MP

SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin
INC_DIR		= include
VENDOR_DIR	= vendor

SRCS		= $(shell find $(SRC_DIR) -name '*.cpp')
OBJS		= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

GLAD_INC	= $(VENDOR_DIR)/glad/include
GLAD_SRC	= $(VENDOR_DIR)/glad/src/gl.c
GLAD_OBJ	= $(OBJ_DIR)/vendor/glad/gl.o
STB_INC		= $(VENDOR_DIR)/stb

OBJS		+= $(GLAD_OBJ)

PKG_CFLAGS	= $(shell pkg-config --cflags glfw3)
PKG_LIBS	= $(shell pkg-config --libs glfw3)

UNAME_S		= $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	GL_LIBS	= -framework OpenGL
else
	GL_LIBS	= -lGL
endif

INCLUDES	= -I$(INC_DIR) -I$(GLAD_INC) -I$(STB_INC) $(PKG_CFLAGS)
LDLIBS		= $(PKG_LIBS) $(GL_LIBS)

BIN			= $(BIN_DIR)/$(NAME)

all: $(BIN)

$(BIN): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) $(LDLIBS) -o $(BIN)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(GLAD_OBJ): $(GLAD_SRC)
	@mkdir -p $(dir $@)
	$(CC) -fPIC -I$(GLAD_INC) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
