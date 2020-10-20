# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 18:36:11 by lde-moul          #+#    #+#              #
#    Updated: 2020/10/20 15:29:44 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = avm

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj

SRC = Lexer.cpp\
      LexerError.cpp\
      LexerToken.cpp\
      Main.cpp\

DEP = Lexer.hpp\
      LexerError.hpp\
      LexerToken.hpp\
      LexerTokenType.hpp\

OBJ := $(SRC:%.cpp=$(OBJDIR)/%.o)
SRC := $(SRC:%=$(SRCDIR)/%)
DEP := $(DEP:%=$(SRCDIR)/%)


all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

$(NAME): $(OBJDIR) $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEP)
	@$(CXX) -std=c++11 $(CXXFLAGS) -o $@ -c $<

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

.PHONY: all clean fclean re
