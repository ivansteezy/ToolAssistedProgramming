#include "DataParser.hpp"

namespace Tap
{
	DataParser::DataParser(FileDataMap fileData)
	{

	}

	DataParser::DataParser(FileDataLines filelines) : m_fileLines(filelines)
	{

	}

	void DataParser::SortLines()
	{
		std::sort(std::begin(m_fileLines), std::end(m_fileLines), [](std::string const& a, std::string const& b) {
			return std::lexicographical_compare(std::begin(a), std::begin(a) + 2, std::begin(b), std::begin(b) + 2);
		});

		for (auto const& s : m_fileLines)
		{
			std::cout << s << '\n';
		}

		//sorting done
	}

	void DataParser::BuildCommandPayLoad()
	{

	}

	void DataParser::ConsolidateNavigationComand()
	{

	}

	void DataParser::SanitizeLine()
	{

	}
}