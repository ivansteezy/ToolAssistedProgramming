#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Foundation.hpp"

namespace Tap
{
	enum ArrowNavigation
	{
		Up   = 0x0,
		Down = 0x1,
		None = 0x2
	};

	struct LineMetadata
	{
		std::size_t orderValue;
		std::string text;
		std::pair<ArrowNavigation, int> navigationCommads;
	};

	class DataParser
	{
	public:
		DataParser() = default;
		DataParser(FileDataMap fileData);
		DataParser(FileDataLines filelines);

	public:
		void SortLines();

	public:
		FileDataLines m_fileLines;
		std::map<int, std::string> m_mapToOrder;
	};
}

#endif