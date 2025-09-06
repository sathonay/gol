SRC=	\
	main.c \
	mlx_hooks.c \
	renderer.c \
	parser.c \
	minilibft.c \
	draw_rect.c \
	image_util.c \
	math_util.c \
	tinyprintf.c \

TARGET_FOLDER	= target/
OBJ_FOLDER	= $(TARGET_FOLDER)objects/
OBJ		= $(addprefix $(OBJ_FOLDER), $(SRC:.c=.o)) 

MINILIBX_DIR = minilibx
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

CC = cc
FLAGS=-Wall -Wextra -Werror 
INCLUDES= -I $(MINILIBX_DIR) 
LIBS= $(MINILIBX_LIB)

TARGET = gol 

SHELL = bash

RESET	= \x1b[1;0m
BLACK	= \x1b[1;30m
RED	= \x1b[1;31m
GREEN	= \x1b[1;32m
YELLOW	= \x1b[1;33m
BLUE	= \x1b[1;34m
PURPLE	= \x1b[1;35m
CYAN	= \x1b[1;36m
WHITE	= \x1b[1;37m

BORDER_C = $(PURPLE)

OVERLAP = 0

CAT_C = $(PURPLE)
CATE_C = $(RED)

define box
	@tput civis
	$(if $(filter $(3), 0), ,@tput cuu $(3))
	@printf "$(BORDER_C)%s%s%s%16s\n" "╘╪" "─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─" "╪╛" ""
	@printf "%-20s $(1)%-29s$(RESET)$(BORDER_C)%s%16s\n" "╞╫" "$(2)" "╫╡" ""
	@printf "%s%s%s$(RESET)%16s\n" "╒╪" "─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─" "╪╕" ""
	@tput cnorm	
endef

$(TARGET): $(MINILIBX_LIB) $(OBJ) | cat 
	$(call box, $(YELLOW), BUILDING EXECUTABLE..., 0)
	@$(CC) $(OBJ) $(LIBS) -lXext -lX11 -lm -o $(TARGET)  
	$(call box, $(GREEN), BUILDING EXECUTABLE, $(OVERLAP))

$(OBJ_FOLDER)%.o: %.c
	$(call box, $(YELLOW), $<, 0)
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call box, $(GREEN), $<, $(OVERLAP))

$(MINILIBX_LIB): | cat
	$(call box, $(YELLOW), BUILDING MINILIBX..., 0)
	@git clone https://github.com/42Paris/minilibx-linux $(MINILIBX_DIR)
	@make --silent -C $(MINILIBX_DIR)
	$(call box, $(GREEN), MINILIBX BUILD SUCCESS, $(OVERLAP))

cat: 
	@echo -e "$(CAT_C)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀ "
	@echo -e "$(CAT_C)⠀⠀⠀⠀⢀⡴⣆⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⣼⣿⡗⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⠀⣠⠟⠀⠘⠷⠶⠶⠶⠾⠉⢳⡄⠀⠀⠀⠀⠀⣧⣿⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣤⣤⣤⣤⣤⣿⢿⣄⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⡇⠀$(CATE_C)x⠀⠀⠀⠀⠀x$(CAT_C)⠀⠀⠀⠀⣧⠀⠀⠀⠀⠀⠀⠙⣷⡴⠶⣦"
	@echo -e "$(CAT_C)⠀⠀⢱⡀⠀ ⠉⠉⠀⠀⠀  ⠀⢠⡟⠂⠀⠀⢀⣀⣠⣤⠿⠞⠛⠋"
	@echo -e "$(CAT_C)⣠⠾⠋⠙⣶⣤⣤⣤⣤⣤⣀⣠⣤⣾⣿⠴⠶⠚⠋⠉⠁⠀⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠛⠒⠛⠉⠉⠀⠀⠀⣴⠟⣣⡴⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"

all: $(TARGET)

re: cat clean all

exec: re
	./$(TARGET) mandel
valgrind: re
	valgrind --leak-check=full ./$(TARGET) mandel
clean: cat 
	$(call box, $(RED), CLEANING, 0)
	@rm -fr $(TARGET_FOLDER) 
	@rm -fr $(TARGET) 
	$(call box, $(GREEN), CLEANING, $(OVERLAP))

fclean: cat clean
	$(call box, $(RED), CLEANING LIBS, 0)
	@rm -fr $(MINILIBX_DIR)
	$(call box, $(GREEN), CLEANING LIBS, $(OVERLAP))

.PHONY: all re clean fclean cat
