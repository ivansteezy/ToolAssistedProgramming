#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <utility>
#include <cassert>
#include <string>
#include <map>

#include "Foundation.hpp"

namespace fs = std::filesystem;

namespace Tap
{
	enum class FileInputType
	{
		File      = 0x0,
		Directory = 0x1
	};

	class FileManager
	{
	public:
		FileManager() = default;
		FileManager(FileInputType type, fs::path itemPath);

	public:
		FileDataMap GetDirectoryFilesMap() const;
		std::vector<std::string> GetFileLines() const;

	private:
		void BuildFileLines();
		void BuildDirectoryFilesMap();

		std::vector<fs::path> FetchFilesInDirectory() const;

	private:
		fs::path m_itemPath;
		FileInputType m_type;
		fs::directory_iterator entryFiles;
		std::vector<std::string> m_fileRawLines;
		FileDataMap m_directoryRawFilesMap;
	};
}

#endif