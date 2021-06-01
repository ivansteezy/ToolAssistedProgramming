#include "DataWriter.hpp"

namespace Tap
{
	DataWriter::DataWriter() : 
		m_speed(20),
		m_waitFor(2),
		m_input{0}
	{

	}

	DataWriter::DataWriter(CommandPayload payload) :
		m_speed(20),
		m_waitFor(2),
		m_commandPayload(payload),
		m_input{0}
	{

	}

	void DataWriter::BeginChoreography()
	{
		std::cout << "comenzara a escribir! :D" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "A escribir!!!!" << std::endl;
		for (auto line : m_commandPayload)
		{
			std::string newline = line.text.substr(0, line.text.find_first_of('\0'));
			WriteText(newline);
			if (!line.navigationCommads.empty())
			{
				WriteCommands(line.navigationCommads);
			}
		}
	}

	void DataWriter::SetWriteSpeed(std::chrono::milliseconds millis)
	{

	}

	void DataWriter::SetTimeToWait(std::chrono::seconds waitFor)
	{

	}

	void DataWriter::WriteText(const std::string& line)
	{
		for (const auto& c : line)
		{
			m_input.type = INPUT_KEYBOARD;
			m_input.ki.dwFlags = KEYEVENTF_UNICODE;
			m_input.ki.wScan = c;

			SendInput(1, &m_input, sizeof(INPUT));
			m_input.ki.dwFlags |= KEYEVENTF_KEYUP;
			SendInput(1, &m_input, sizeof(INPUT));
			std::this_thread::sleep_for(std::chrono::milliseconds(m_speed));
		}

		WriteLineJump();
	}

	void DataWriter::WriteLineJump()
	{
		m_input.type = INPUT_KEYBOARD;
		m_input.ki.dwFlags = KEYEVENTF_UNICODE;
		m_input.ki.wScan = '\n';

		SendInput(1, &m_input, sizeof(INPUT));
		m_input.ki.dwFlags |= KEYEVENTF_KEYUP;
		SendInput(1, &m_input, sizeof(INPUT));
		std::this_thread::sleep_for(std::chrono::milliseconds(m_speed));
	}

	void DataWriter::WriteCommands(const std::vector<Command>& commands)
	{
		INPUT in = { 0 };
		for (const auto& cmd : commands)
		{
			for (auto i = 0; i < cmd.numberOfTimes; i++)
			{
				in.type = INPUT_KEYBOARD;
				in.ki.wScan = 0;
				in.ki.wVk = MapCommandToVirtualKey(cmd.command);
				SendInput(1, &in, sizeof(INPUT));
				in.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &in, sizeof(INPUT));
				
				in.ki.dwFlags = 0;
			}
		}
	}

	int DataWriter::MapCommandToVirtualKey(const KeyboardCommand& keyboardCommand)
	{
		switch (keyboardCommand)
		{
			case KeyboardCommand::Up:       return VK_UP;     break;
			case KeyboardCommand::Down:     return VK_DOWN;   break;
			case KeyboardCommand::Left:     return VK_LEFT;   break;
			case KeyboardCommand::Right:    return VK_RIGHT;  break;
			case KeyboardCommand::Home:	    return VK_HOME;   break;
			case KeyboardCommand::End:	    return VK_END;    break;
			case KeyboardCommand::Delete:   return VK_DELETE; break;
			case KeyboardCommand::PageUp:   return VK_PRIOR;  break;
			case KeyboardCommand::PageDown: return VK_NEXT;   break;
		}
	}
}