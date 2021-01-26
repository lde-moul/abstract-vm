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
      Parser.cpp\
      ParserError.cpp\
      VirtualMachineError.cpp\
      VirtualMachineStack.cpp\

DEP = Instruction.hpp\
      InstructionType.hpp\
      Int8.hpp\
      Int16.hpp\
      Int32.hpp\
      Float.hpp\
      Double.hpp\
      IOperand.hpp\
      Lexer.hpp\
      LexerError.hpp\
      LexerToken.hpp\
      LexerTokenType.hpp\
      OperandFactory.hpp\
      OperandType.hpp\
      Parser.hpp\
      ParserError.hpp\
      VirtualMachineError.hpp\
      VirtualMachineStack.hpp\

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
