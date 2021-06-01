#ifndef DATAWRITER_HPP
#define DATAWRITER_HPP

#include <Windows.h>
#include "Foundation.hpp"

namespace Tap
{
	class DataWriter
	{
	public:
		DataWriter();
		DataWriter(CommandPayload payload);

	public:
		void BeginChoreography();
		void SetWriteSpeed(std::chrono::milliseconds millis);
		void SetTimeToWait(std::chrono::seconds waitFor);

	private:
		void WriteText(const std::string& line);
		void WriteCommands(const std::vector<Command>& commads);
		void WriteLineJump();
		int MapCommandToVirtualKey(const KeyboardCommand& keyboardCommand);

	private:
		CommandPayload m_commandPayload;
		std::chrono::milliseconds m_speed;
		std::chrono::seconds m_waitFor;
		INPUT m_input;
	};
}

#endif
