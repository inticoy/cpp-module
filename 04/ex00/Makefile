# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/10/23 20:35:42 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= polymorphism

# **************************************************************************** #
#                                                                              #
#    Options                                                                   #
#                                                                              #
# **************************************************************************** #

CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

# **************************************************************************** #
#                                                                              #
#    Source Files                                                              #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.cpp \
				Animal.cpp Cat.cpp Dog.cpp \
				WrongAnimal.cpp WrongCat.cpp WrongDog.cpp
OBJS		= 	${SRCS:.cpp=.o}
INC			= 	./

# **************************************************************************** #
#                                                                              #
#    Progress                                                                  #
#                                                                              #
# **************************************************************************** #

num_file	= $(shell echo $(SRCS) | tr ' ' '\n' | wc -w)
cnt			:= 0
bar_done	= '🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩'
bar_ready	= '⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️'

#			COLOR
red			= \e[1;31m
grn			= \e[1;32m
yel			= \e[1;33m
blu			= \e[1;34m
mag			= \e[1;35m
cyn			= \e[1;36m
bold		= \e[1;37m
end			= \e[0m

version = "mandatory version"

# **************************************************************************** #
#                                                                              #
#    Executable Section                                                        #
#                                                                              #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $@
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "💥 Now you can execute ${bold}$(NAME).${end}"
	@printf " (%s)\n" $(version)

%.o : %.cpp
	@$(eval cnt=$(shell printf $$(($(cnt)+1))))
	@$(eval rate_hex=$(shell echo "scale=2; ($(cnt) / $(num_file)) * 16" | bc))
	@$(eval len=$(shell printf "%.0f\n" $(rate_hex)))
	@$(eval len_done=$(shell echo "scale=0; $(len) * 4" | bc))
	@$(eval len_ready=$(shell echo "scale=0; 96 - ($(len_done) / 4) * 6" | bc))
	@$(eval percent=$(shell echo "scale=4; ($(cnt) / $(num_file)) * 100" | bc))
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" $(len_done))s" $(bar_done)
	@printf "%.$(shell printf "%d" $(len_ready))s" $(bar_ready)
	@printf "%7.2f%%" $(percent)
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)
	@printf "make clean ${bold}$(NAME).${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@printf "make fclean ${bold}$(NAME).${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re
