CC = cc 
FLAGS = -Wall -Wextra -Werror -O3 -lmlx -framework OpenGL -framework AppKit
CFILES = main.c mandelbrot.c move_esc.c zoom.c tools.c julia.c
OFILES = ${CFILES:.c=.o}
NAME = fractol.a

all :
	${CC} ${FLAGS} ${CFILES} -o fractol
clean :
	rm ${OFILES} fractol
fclean : clean
	rm ${NAME}
re : fclean all

#	//gcc test.c -lmlx -framework OpenGl -framework Appkit -lz minilibx_opengl_20191021/libmlx.a
#	//gcc mandel_ex.c -O3 -lmlx -framework OpenGL -framework AppKit