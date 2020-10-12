#include "LexerError.hpp"

#include <string>

LexerError::LexerError(uint32_t lineNum) : std::runtime_error("syntax error at line " + std::to_string(lineNum)) {}
