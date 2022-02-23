#include "ParserError.hpp"

#include <string>

ParserError::ParserError() : ParserError("syntax error") {}

ParserError::ParserError(uint32_t lineNum) : ParserError("syntax error", lineNum) {}

ParserError::ParserError(std::string message) : std::runtime_error(message + " at end of file") {}

ParserError::ParserError(std::string message, uint32_t lineNum) : std::runtime_error(message + " at line " + std::to_string(lineNum)) {}

ParserRangeError::ParserRangeError(uint32_t lineNum) : ParserError("value out of range", lineNum) {}
