#include "Lexer.hpp"
#include "LexerError.hpp"
#include "Parser.hpp"
#include "ParserError.hpp"
#include "VirtualMachine.hpp"
#include "VirtualMachineError.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	std::ostringstream codeStream;

	if (argc == 1)
	{
		std::string line;

		while (std::getline(std::cin, line))
		{
			if (line != ";;")
				codeStream << line << std::endl;
			else
				break;
		}
	}
	else
	{
		std::ifstream file(argv[1]);
		codeStream << file.rdbuf();
	}

	std::string code = codeStream.str();

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
