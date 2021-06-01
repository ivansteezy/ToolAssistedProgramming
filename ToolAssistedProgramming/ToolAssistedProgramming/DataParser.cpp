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
		auto splitedLine = SanitizeLine(line);

		lm.orderValue = DeserializeOrderValue(splitedLine.arguments);
		lm.navigationCommads = DeserializeCommands(splitedLine.arguments);
		lm.text = splitedLine.text;
		return lm;
	}

	void DataParser::RemoveTab() // ???
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
		std::vector<Command> cmds;
		KeyboardCommand keyboardCommand = KeyboardCommand::None;

		if (stringCommand.find("~") == std::string::npos)
		{
			// cmds.push_back({ KeyboardCommand::None, 0 });
			return cmds;
		}

		for (auto i = 0; i < stringCommand.size(); i++)
		{
			if (stringCommand[i] == '~')
			{
				keyboardCommand = MapTokenToCommand(stringCommand[i + 1]);
				
				if (stringCommand[i + 2] != '(')
				{
					cmds.push_back({ keyboardCommand, 1 });
				}
			}
			if (stringCommand[i] == '(')
			{
				auto delimiter = stringCommand.find_first_of(')');
				auto repetitionString = std::string(stringCommand.c_str() + (i + 1), (delimiter - 1) - i);
				auto repetitions = std::stoi(repetitionString);
					
				cmds.push_back({ keyboardCommand, repetitions });
			}
		}
		return cmds;
	}

	KeyboardCommand DataParser::MapTokenToCommand(const char command)
	{
		switch (command)
		{
			case '^': return KeyboardCommand::Up;       break;
			case 'v': return KeyboardCommand::Down;     break;
			case '<': return KeyboardCommand::Left;     break;
			case '>': return KeyboardCommand::Right;    break;
			case 'h': return KeyboardCommand::Home;     break;
			case 'n': return KeyboardCommand::End;      break;
			case 'e': return KeyboardCommand::Delete;   break;
			case 'u': return KeyboardCommand::PageUp;   break;
			case 'd': return KeyboardCommand::PageDown; break;
		}
	}

	[[nodiscard]]
	CommandPayload DataParser::GetCommandPayload() const
	{
		return m_commandPayload;
	}

	int DataParser::DeserializeOrderValue(const std::string& value)
	{
		if (value.find("~") != std::string::npos)
		{
			auto orderValue = value.substr(0, value.find("~"));
			return std::stoi(orderValue);
		}
		else 
		{
			auto orderValue = value.substr(0, value.find("\t"));
			return std::stoi(orderValue);
		}
	}


	SplitedLine DataParser::SanitizeLine(const std::string& line)
	{
		SplitedLine sl;
		auto sanitizeArguments = std::string(line.c_str() + 0, 20 - 0);
		sanitizeArguments.erase(std::remove_if(sanitizeArguments.begin(), 
								sanitizeArguments.end(), isspace), sanitizeArguments.end());
		sl.arguments = sanitizeArguments;

		auto sanitizeText = std::string(line.c_str() + 20, line.size());
		sl.text = sanitizeText;
		return sl;
	}
}