#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <filesystem>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <map>

namespace fs = std::filesystem;

namespace File
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
		void BuildDirectoryFilesMap();
		std::map<std::string, std::vector<std::string>> GetDirectoryFilesMap() const;

	private:
		void OpenFile();
		void OpenDirectory();
		std::vector<fs::path> FetchFilesInDirectory() const;

	private:
		fs::path m_itemPath;
		fs::directory_iterator entryFiles;
		std::map<std::string, std::vector<std::string>> m_directoryRawFilesMap;
		std::vector<std::string> m_fileRawLines;
	};
}

#endif