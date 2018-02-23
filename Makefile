# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 14:43:13 by niragne           #+#    #+#              #
#    Updated: 2018/02/23 16:05:19 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libmat.a

CC				=	gcc
RM				=	/bin/rm

CFLAGS			=	-Wall -Wextra -Werror -Ofast

SRCS			=	mat4_new.c mat3_new.c mat3_mult.c mat4_mult.c mat3_id_new.c \
					mat4_id_new.c mat4_rotate.c vec3_normalize.c mat4_zoom.c \
					mat4_translate.c vec3_cross.c vec3_add.c vec3_sub.c mat4_perspective.c \
					vec3_dot.c cam_lookat.c cam_move.c cam_orient.c cam_settarget.c

SRC_DIR			=	src
OBJ_DIR			=	obj

SRC				=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCL_DIR 		= 	include
INCL			=	$(INCL_DIR)/libmat.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_DIR)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re : fclean
	make -j

.PHONY: all clean fclean re
