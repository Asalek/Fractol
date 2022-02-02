CC = cc 
CFLAGS = -Wall -Wextra -Werror
CFILES = main.c src/mandelbrot.c src/move_esc.c src/zoom.c \
			src/tools.c src/julia.c src/burningship.c
OFILES = $(CFILES:.c=.o)
NAME = fractol
UNAME = $(shell uname -s)
SRC = src
LIB = fractol.a

ifeq ($(UNAME), Darwin)
MLXFLAGS =  -O3 -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME), Linux)
MLXFLAGS = -lmlx -lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OFILES)
	${CC} $^ -o $@ ${MLXFLAGS}
	ar -r $(LIB) $(OFILES)

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm ${OFILES} $(LIB)

fclean : clean
	rm -rf ${NAME}

re : fclean all

bonus : all

#	//gcc test.c -lmlx -framework OpenGl -framework Appkit -lz minilibx_opengl_20191021/libmlx.a
#	//gcc mandel_ex.c -O3 -lmlx -framework OpenGL -framework AppKit