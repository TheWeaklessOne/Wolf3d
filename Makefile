NAME		=	wolf3d


CC		=	gcc

uname_S		:= $(shell uname -s)

FLAGS	=	-g3 -lSDL2 -lSDL2_image -Ofast

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

SRC_DIR		=	Sources/
INC_DIR		=	Includes/
OBJ_DIR		=	.objs/

SRC_BASE	=	keys.c			\
				main.c			\
				sdl.c			\
				sdl_init.c		\
				wolf_init.c		\
				walls_init.c	\
				Utils/ft.c		\
				Utils/ft_2.c	\
				Utils/get_nl.c	\
				Utils/list.c	\
				Utils/list_2.c	\
				Map/add_to_text.c	\
				Map/check_file.c	\
				Map/read_map.c		\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB		=	$(words $(SRC_BASE))
INDEX		=	0

all:
	@make -j $(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)	\
	-I $(INC_DIR)			\
	$(LIBS)                 	\
	$(FLAGS)
	@strip -x $@
	@printf "\r\033[48;5;15;38;5;25m✅   MAKE $(NAME)\033[0m\033[K\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m %*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@$(CC) -MMD -c $< -o $@\
		-I $(INC_DIR)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

clean:
	@rm -rf $(OBJ_DIR)
	@printf "\r\033[38;5;202m✖  clean $(NAME)\033[0m\033[K\n"

fclean:		clean
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K\n"

re:		fclean all

install:
	@./install_frameworks.sh


-include $(OBJS:.o=.d)
