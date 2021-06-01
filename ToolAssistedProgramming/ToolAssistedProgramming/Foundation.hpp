#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>


enum class KeyboardCommand : std::uint8_t
{
	Up		 = 0x00,    // ~^
	Down	 = 0x01,    // ~v
	Left	 = 0x02,    // ~<
	Right	 = 0x03,    // ~>
	Home	 = 0x04,    // ~h
	End		 = 0x05,    // ~n
	Delete	 = 0x06,    // ~e
	PageUp	 = 0x07,    // ~u
	PageDown = 0x08,    // ~d
	None	 = 0xFF	    // ~x
};

struct Command
{
	KeyboardCommand command;
	int numberOfTimes;
};

struct LineMetadata
{
	std::size_t orderValue;
	std::string text;
	std::vector<Command> navigationCommads; // should be a stack insted?
};

struct SplitedLine
{
	std::string arguments;
	std::string text;
};

using FileDataMap    = std::map<std::string, std::vector<std::string>>;
using FileDataLines  = std::vector<std::string>;
using CommandPayload = std::vector<LineMetadata>;

#endif // !FOUNDATION_H
