#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <filesystem>
#include <iostream>
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
		FileManager(FileInputType type, fs::path itemPath);

	private:
		void OpenFile();
		void OpenDirectory();
		fs::directory_iterator GetFilesInDirectory();

	private:
		fs::path m_itemPath;
		fs::directory_iterator entryFiles;
	};
}

#endif