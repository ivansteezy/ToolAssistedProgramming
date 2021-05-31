#include "DataParser.hpp"

namespace Tap
{
	DataParser::DataParser(FileDataMap fileData)
	{

	}

	DataParser::DataParser(FileDataLines filelines) : m_fileLines(filelines)
	{
		SortLines();
	}

	void DataParser::SortLines()
	{
		std::sort(std::begin(m_fileLines), std::end(m_fileLines), [](std::string const& a, std::string const& b) {
			return std::lexicographical_compare(std::begin(a), std::begin(a) + 2, std::begin(b), std::begin(b) + 2);
		});

		RemoveTab();
	}

	void DataParser::BuildCommandPayLoad()
	{
		for (auto& line : m_fileLines)
		{
			auto lineMetadata = BuildLineMetadata(line);
			m_commandPayload.push_back(lineMetadata);
		}
	}

	LineMetadata DataParser::BuildLineMetadata(std::string& line)
	{
		LineMetadata lm;
		lm.orderValue = DeserializeOrderValue(line);
		lm.navigationCommads = DeserializeCommands(line);
		lm.text = line;
		return lm;
	}

	void DataParser::RemoveTab()
	{
		constexpr std::string_view sequenceToRemove = "\t\t\t\t";
		for (auto& line : m_fileLines)
		{
			auto initialPosition = line.find(sequenceToRemove);
			if (initialPosition != std::string::npos)
				line.erase(initialPosition, sequenceToRemove.length());
		}

		BuildCommandPayLoad();
	}

	std::vector<Command> DataParser::DeserializeCommands(const std::string& stringCommand)
	{
		// sample line (4th line in the example listing file):
		// 10~^(3)~hm press up-key 3 times then press home page
		// 1.-find the "~" character, identtify the proceded token
		// 2.-identify the number of times to execute that command
		// 3.-stack the command
		// 4.-identify if proceed another "~" token, repeat step 1
		std::cout << stringCommand << std::endl;
		return std::vector<Command>();
	}

	int DataParser::DeserializeOrderValue(const std::string& line)
	{
		// 1.-find the "~" character
		// 2.-All the numbers before that caracter parse into a int, 
		// then return
		return 0;
	}

	void DataParser::SanitizeLine()
	{

	}
}