#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP
#include <map>
#include <vector>
#include <string>

namespace Parser
{
	class DataParser
	{
	public:
		DataParser() = default;
		DataParser(std::map<std::string, std::vector<std::string>>);


	};
}

#endif