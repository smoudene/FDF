# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoudene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 15:10:07 by smoudene          #+#    #+#              #
#    Updated: 2020/02/24 15:10:24 by smoudene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

SRCS = *.c

FLAGS = -Wall -Werror -Wextra -I ./includes 

OBJ = $(SRCS:.c=.o) 

all: $(NAME) 
 		$(NAME): $(OBJ)	make -C libft	gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a	
	 	echo "done"

clean:	
		make clean -C libft	rm -f $(OBJ) 

fclean: 
	clean	make fclean -C libft	rm -f $(NAME) 

re: 
	fclean all