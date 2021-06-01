#ifndef DATAWRITER_HPP
#define DATAWRITER_HPP

#include "Foundation.hpp"

namespace Tap
{
	class DataWriter
	{
	public:
		DataWriter(CommandPayload payload);

	public:
		void BeginChoreography();
		void SetWriteSpeed(std::chrono::milliseconds millis);
		void SetTimeToWait(std::chrono::seconds waitFor);

	private:
		void WriteText();
		void WriteCommand();

	private:
		CommandPayload m_commandPayload;
		std::chrono::milliseconds m_speed;
		std::chrono::seconds m_waitFor;
	};
}

#endif
