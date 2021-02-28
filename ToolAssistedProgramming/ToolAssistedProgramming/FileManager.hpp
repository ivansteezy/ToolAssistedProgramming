#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <utility>
#include <cassert>
#include <string>
#include <map>

namespace fs = std::filesystem;

namespace File
{
	struct InputFile {};
	struct InputDirectory {};
	enum class FileInputType
	{
		File      = 0x0,
		Directory = 0x1
	};

	template<typename T>
	class FileManager
	{
	public:
		FileManager() = default;
		FileManager(fs::path itemPath);

	public:
		std::map<std::string, std::vector<std::string>> GetDirectoryFilesMap() const;
		std::vector<std::string> GetFileLines() const;

	private:
		void BuildFileLines();
		void BuildDirectoryFilesMap();

		std::vector<fs::path> FetchFilesInDirectory() const;

	private:
		fs::path m_itemPath;
		fs::directory_iterator entryFiles;
		std::map<std::string, std::vector<std::string>> m_directoryRawFilesMap;
		std::vector<std::string> m_fileRawLines;
	};
}

#endif