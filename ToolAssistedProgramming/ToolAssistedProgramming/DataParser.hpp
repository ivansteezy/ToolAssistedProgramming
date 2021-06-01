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
		CommandPayload GetCommandPayload() const;

	private:
		std::vector<Command> DeserializeCommands(const std::string& stringCommand);
		KeyboardCommand MapTokenToCommand(const char command);
		int DeserializeOrderValue(const std::string& value);
		LineMetadata BuildLineMetadata(std::string& line);
		SplitedLine SanitizeLine(const std::string& line);
		void BuildCommandPayLoad();
		void SortLines();
		void RemoveTab();


	private:
		FileDataLines m_fileLines;
		std::map<int, std::string> m_mapToOrder;
		CommandPayload m_commandPayload;
	};
}

#endif