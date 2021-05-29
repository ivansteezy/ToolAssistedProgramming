#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Foundation.hpp"

namespace Tap
{
	enum KeyboardCommand : std::uint8_t
	{
		Up       = 0x00,	// ~^
		Down     = 0x01,	// ~v
		Left     = 0x02,	// ~<
		Right    = 0x03,	// ~>
		Home     = 0x04,	// ~hm
		End      = 0x05,	// ~nd
		Delete   = 0x06,	// ~dl
		PageUp   = 0x07,	// ~pu
		PageDown = 0x08,	// ~pd
		None     = 0xFF		// ~nn
	};

	struct LineMetadata
	{
		std::size_t orderValue;
		std::string text;
		std::pair<KeyboardCommand, int> navigationCommads;
	};

	class DataParser
	{
	public:
		DataParser() = default;
		DataParser(FileDataMap fileData);
		DataParser(FileDataLines filelines);

	public:
		void SortLines();
		void BuildCommandPayLoad();
		void ConsolidateNavigationComand();
		void SanitizeLine();

	public:
		FileDataLines m_fileLines;
		std::map<int, std::string> m_mapToOrder;
		std::vector<LineMetadata> m_commandPayload;
	};
}

#endif