# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/01 15:43:04 by cpieri            #+#    #+#              #
#    Updated: 2019/01/21 17:54:32 by delay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgraph.a

CC		=	g++

CFLAGS	=	-Wall -Wextra -Werror

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAG	=	-Iinclude

FW_PATH	=	frameworks

SDL_PATH=	$(FW_PATH)/SDL2.framework

IMG_PATH=	$(FW_PATH)/SDL2_image.framework

TTF_PATH=	$(FW_PATH)/SDL2_ttf.framework

SDLFLAG	=	-I$(SDL_PATH)/Headers -I$(IMG_PATH)/Headers -I$(TTF_PATH)/Headers

DEPS =		Makefile			\
			include/display.hpp	\
			include/gb_image.hpp	\
			include/graphics.hpp\
			include/utils.hpp	\
			include/libgraph.hpp\
			include/color.hpp	\
			include/vector.hpp	\
			include/gui_button.hpp	\
			include/button.hpp		\
			include/gamebuino_sdl.hpp

SRCS = 		color.cpp			\
			utils.cpp			\
			display.cpp			\
			image.cpp			\
			graphics.cpp		\
			bloc.cpp			\
			button.cpp			\
			gui_button.cpp		\
			vector3d.cpp		\
			vector4d.cpp		\
			vector2d.cpp		\
			vector_op.cpp		\
			gamebuino_sdl.cpp


OBJS	=	$(SRCS:.cpp=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRCS) )

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJS) )

.PHONY: all clean fclean re echo

all:		echo $(NAME)

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

echo:
			@echo -n Getting libgraph ready

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(DEPS)
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAG) $(SDLFLAG) -o $@ -c $<
			@echo -n .

clean:
			@/bin/rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all
