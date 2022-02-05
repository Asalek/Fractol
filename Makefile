CC = cc 
CFLAGS = -Wall -Wextra -Werror
CFILES = main.c src/mandelbrot.c src/move_esc.c src/zoom.c \
			src/tools.c src/julia.c src/burningship.c
OFILES = $(CFILES:.c=.o)
NAME = fractol
UNAME = $(shell uname -s)
SRC = src
LIB = fractol.a
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
HPATH = include

ifeq ($(UNAME), Darwin)
MLXFLAGS =  -O3 -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
MLXFLAGS = -lmlx -lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OFILES)
	@echo "$(GREEN)*******ALL********"
	@${CC} $^ -o $@ ${MLXFLAGS}
	@ar -r $(LIB) $(OFILES)

#  $^ : all
#  $< : will point the first file in the dependency chain
#  $@ : will point the last file in the dependency chain 

$(SRC)/%.o: $(SRC)/%.c $(HPATH)/%.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf ${NAME}
	@echo "$(RED)*******CLEAN********"

fclean : clean
	@rm ${OFILES} $(LIB)
	@echo "$(YELLOW)*******fclean********"

re : fclean all
	@echo "$(YELLOW)*******RE********"

bonus : all

#	//gcc test.c -lmlx -framework OpenGl -framework Appkit -lz minilibx_opengl_20191021/libmlx.a
#	//gcc mandel_ex.c -O3 -lmlx -framework OpenGL -framework AppKit