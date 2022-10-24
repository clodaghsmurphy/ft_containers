# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/10/24 10:51:04 by clmurphy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET="\033[0m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

SRC =	$(addsuffix .cpp, 	\
		$(addprefix src/,	\
		main				\
		modifiers				\
		iterator_category				\
		test_vector_size	\
		vector_constructors \
		))


SHELL := /bin/zsh

OBJ		= ${SRC:src/%.cpp=obj/%.o}

DEP		= ${SRC:src/%.cpp=dep/%.d}

OBJ_FILE = ./obj

DEP_FILE = ./dep

CC		= c++

INCLUDE = -Iinclude/

CFLAGS	= -Wall -Werror -Wextra -MMD ${INCLUDE} -g  -std=c++98 #-fsanitize=address

NAME	= ft_containers

MAKE	= --silent --jobs

MY_MAKE	= make --silent --jobs

total	:= $(shell echo ${SRC} | wc -w)

percent	:= 0

current	:= 1

save_percent ?= 0

len := $(shell echo ${NAME} | wc -c)

all:
	@${MY_MAKE} setup
	@echo -ne "\033[5;3H\033[1;32mObject already compiled !\033[m";
	@make --silent ${OBJ}
	@echo -ne "\033[9;3H\033[1;32m${NAME} Already compiled !\033[m";
	@echo -ne "\033[16;H"
	@make --silent ${NAME}
	@${MY_MAKE} end_make

obj/%.o: src/%.cpp
	@printf "\033[10;2H                                                  \033[10;3H%s" $< ${<:.c=⠀⠀}
	@echo -ne "\033[16;H"
	@mkdir -p $(OBJ_FILE)
	@mkdir -p $(DEP_FILE)
	@${CC} ${CFLAGS} -c $< -o ${<:src/%.cpp=obj/%.o}	
	@$(eval percent=$(shell expr ${current} "*" 100 / ${total}))
	@echo -ne "\033[11;3H"
	@printf "%d/%d:   \t\t%d%%" ${current} ${total} ${percent}
	$(call loading,${percent})
	@$(eval current=$(shell expr ${current} + 1))

${NAME}: ${OBJ}
	${CC} ${OBJ} ${CFLAGS} -o ${NAME};
	@printf "\033[14;3H\033[1m ${NAME} \033[32mCompiled !\033[1;37m!";
	@${MY_MAKE} end_make

setup:
	@echo -ne "\033[0;0H\033[J\033[?25l"
	@echo -ne "\033[1;38;5;57m"
	@echo "╔══════════════════════════════════════════════════╗"
	@echo "╟────────────────┤ \033[3mTURBO MAKEFILE ├────────────────╢"
	@echo "║ Objets:                                          ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║ Executable:                                      ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "║                                                  ║"
	@echo "╚══════════════════════════════════════════════════╝"
	@echo -ne "\033[m"

define loading
	@$(eval save_percent=$(shell expr ${percent}))
	@echo -ne "\033[12;13H"
	@save_percent=$(shell expr ${save_percent} "*" 2); \
	while (( $${save_percent} > 7)) ; do \
		echo -ne "\033[47;32m█"; \
		((save_percent-=7)); \
	done;	\
	echo "\u`printf '%x' $(expr 9608 + $$save_percent)`"		
	@echo -ne "\033[0m"
	@true
endef

end_make:
	echo -ne "\033[16;H\033[?25h"

re: fclean all

fclean:
	@rm -rf ${OBJ} $(OBJ_FILE) $(DEP) $(DEP_FILE)

clean:
	@rm -rf ${OBJ} $(OBJ_FILE) $(DEP) $(DEP_FILE)

.PHONY: clean fclean re end_make all setup
