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

	}

	void DataParser::BuildLineMetadata()
	{

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
	}

	void DataParser::SanitizeLine()
	{

	}
}