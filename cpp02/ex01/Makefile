# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 11:35:42 by tle-moel          #+#    #+#              #
#    Updated: 2024/11/19 11:35:45 by tle-moel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CPP = c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRCS = main.cpp Fixed.cpp
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# ANSI color codes
GREEN       = \033[0;32m
RED         = \033[0;31m
NC          = \033[0m

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAG) $(OBJS) -o $(NAME)
	@echo -e '${GREEN}Build complete!${NC}'

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CPP) $(CPPFLAG) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJDIR)
	@echo -e '${RED}Clean complete!${NC}'

fclean: clean
	$(RM) $(NAME)
	@echo -e '${RED}Build deleted!${NC}'
	@echo -ne '\n'

re: fclean all

.PHONY: all clean fclean re