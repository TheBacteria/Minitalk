# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 17:10:46 by mzouine           #+#    #+#              #
#    Updated: 2024/02/23 20:18:30 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

SRC_CLIENT = client.c mz_pid_conv.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c mz_pid_conv_bonus.c
SRC_SERVER_BONUS = server_bonus.c
HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)




all: $(CLIENT) $(SERVER)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(CLIENT): $(OBJ_CLIENT)
		$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)
$(SERVER): $(OBJ_SERVER)
		$(CC) $(FLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
		$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) -o $(CLIENT_BONUS)
$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
		$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) -o $(SERVER_BONUS)



bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
		$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus