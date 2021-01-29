#include "ParserError.hpp"

#include <string>

ParserError::ParserError() : std::runtime_error("syntax error at end of file") {}

ParserError::ParserError(uint32_t lineNum) : std::runtime_error("syntax error at line " + std::to_string(lineNum)) {}
