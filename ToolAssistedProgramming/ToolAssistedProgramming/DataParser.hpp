#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Foundation.hpp"

namespace Tap
{
	class DataParser
	{
	public:
		DataParser() = default;
		DataParser(FileDataMap fileData);
		DataParser(FileDataLines filelines);

	public:
		void SortLines();
		void BuildCommandPayLoad();
		LineMetadata BuildLineMetadata(std::string& line);
		void RemoveTab();
		std::vector<Command> DeserializeCommands(const std::string& stringCommand);
		SplitedLine SanitizeLine(const std::string& line);
		int DeserializeOrderValue(const std::string& line);
		KeyboardCommand MapTokenToCommand(const char command);

	public:
		std::vector<LineMetadata> GetCommandPayload() const;

	public:
		FileDataLines m_fileLines;
		std::map<int, std::string> m_mapToOrder;
		std::vector<LineMetadata> m_commandPayload;
	};
}

#endif