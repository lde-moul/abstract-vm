#include "Lexer.hpp"
#include "LexerError.hpp"

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
		(void)tokens;

		return 0;
	}
	catch (LexerError &e)
	{
		std::cerr << e.what();

		return 1;
	}
}
