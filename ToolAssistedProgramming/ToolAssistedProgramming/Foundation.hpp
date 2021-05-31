#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

using FileDataMap = std::map<std::string, std::vector<std::string>>;
using FileDataLines = std::vector<std::string>;

enum KeyboardCommand : std::uint8_t
{
	Up		 = 0x00,    // ~^
	Down	 = 0x01,    // ~v
	Left	 = 0x02,    // ~<
	Right	 = 0x03,    // ~>
	Home	 = 0x04,    // ~hm
	End		 = 0x05,    // ~nd
	Delete	 = 0x06,    // ~dl
	PageUp	 = 0x07,    // ~pu
	PageDown = 0x08,    // ~pd
	None	 = 0xFF	    // ~nn
};

struct Command
{
	KeyboardCommand command;
	std::size_t numberOfTimes;
};

struct LineMetadata
{
	std::size_t orderValue;
	std::string text;
	std::vector<Command> navigationCommads; // should be a stack insted?
};

#endif // !FOUNDATION_H
