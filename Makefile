# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 18:36:11 by lde-moul          #+#    #+#              #
#    Updated: 2020/10/21 17:21:59 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = avm

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj

SRC = Instruction.cpp\
      Int8.cpp\
      Int16.cpp\
      Int32.cpp\
      Float.cpp\
      Double.cpp\
      Lexer.cpp\
      LexerError.cpp\
      LexerToken.cpp\
      Main.cpp\
      OperandFactory.cpp\
      OperandError.cpp\
      Parser.cpp\
      ParserError.cpp\
      VirtualMachine.cpp\
      VirtualMachineError.cpp\
      VirtualMachineStack.cpp\

OBJ := $(SRC:%.cpp=$(OBJDIR)/%.o)
SRC := $(SRC:%=$(SRCDIR)/%)
DEP := $(OBJ:%.o=%.d)


all: $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(DEP)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

$(NAME): $(OBJDIR) $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

-include $(DEP)

$(OBJDIR)/%.o:
	@$(CXX) -std=c++11 -MMD -c -o $@ $(CXXFLAGS) $<

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

.PHONY: all clean fclean re
