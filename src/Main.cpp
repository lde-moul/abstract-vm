#include "Lexer.hpp"
#include "LexerError.hpp"
#include "Parser.hpp"
#include "ParserError.hpp"
#include "VirtualMachine.hpp"
#include "VirtualMachineError.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;

	std::ifstream file(argv[1]);
	std::ostringstream stringStream;
	stringStream << file.rdbuf();
	std::string code = stringStream.str();

	try
	{
		Lexer lexer(code);
		std::vector<LexerToken> const & tokens = lexer.run();

		Parser parser(tokens);
		std::vector<Instruction const *> const & instructions = parser.run();

		VirtualMachine virtualMachine(instructions);
		virtualMachine.run();

		return 0;
	}
	catch (LexerError &e)
	{
		std::cerr << e.what();

		return 1;
	}
	catch (ParserError &e)
	{
		std::cerr << e.what();

		return 1;
	}
	catch (VirtualMachineError &e)
	{
		std::cerr << e.what();

		return 1;
	}
}
