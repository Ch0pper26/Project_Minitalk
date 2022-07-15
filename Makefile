# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblondee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 13:25:08 by eblondee          #+#    #+#              #
#    Updated: 2022/05/25 16:57:48 by eblondee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSS = server.c

SRCSC = client.c

OBJSS = ${SRCSS:.c=.o}

OBJSC = ${SRCSC:.c=.o}

NAMES = server

NAMEC = client

SRCSSB = ./bonus/server_bonus.c

SRCSCB = ./bonus/client_bonus.c

OBJSSB = ${SRCSSB:.c=.o}

OBJSCB = ${SRCSCB:.c=.o}

NAMESB = server_bonus

NAMECB = client_bonus

CC  = gcc

RM  = rm -rf

DIR = ./libft/

LIB = libft.a

CFLAGS  = -Wall -Wextra -Werror -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAMEC} ${NAMES}

bonus:	${NAMECB} ${NAMESB}

$(NAMEC):	${OBJSC}
	make -C ${DIR} ${LIB}
	${CC} ${CFLAGS} ${OBJSC} ${DIR}${LIB} -o ${NAMEC}

$(NAMES):	${OBJSS}
	make -C ${DIR} ${LIB}
	${CC} ${CFLAGS} ${OBJSS} ${DIR}${LIB} -o ${NAMES}

$(NAMECB):	${OBJSCB}
	make -C ${DIR} ${LIB}
	${CC} ${CFLAGS} ${OBJSCB} ${DIR}${LIB} -o ${NAMECB}

$(NAMESB):	${OBJSSB}
	make -C ${DIR} ${LIB}
	${CC} ${CFLAGS} ${OBJSSB} ${DIR}${LIB} -o ${NAMESB}

clean:
	make -C ${DIR} clean
	${RM} ${OBJSS}
	${RM} ${OBJSC}
	${RM} ${OBJSSB}
	${RM} ${OBJSCB}

fclean: clean
	${RM} ${DIR}${LIB}
	${RM} ${NAMES}
	${RM} ${NAMEC}
	${RM} ${NAMESB}
	${RM} ${NAMECB}

re: fclean all

.PHONY: all clean fclean re bonus
