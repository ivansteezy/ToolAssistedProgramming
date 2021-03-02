#include "FileManager.hpp"

namespace File
{
	FileManager::FileManager(FileInputType type, fs::path itemPath)
		: m_itemPath(itemPath),
		  m_type(type)
	{
		if (m_type == FileInputType::File)
		{
			BuildFileLines();
		}
		if (m_type == FileInputType::Directory)
		{
			BuildDirectoryFilesMap();
		}
	}

	void FileManager::BuildFileLines()
	{
		//static_assert(std::is_same<T, InputFile>::value, "The type is not a file");
		std::ifstream file;
		std::string fileLine;

		file.open(m_itemPath.string());
		while (std::getline(file, fileLine))
		{
			m_fileRawLines.push_back(fileLine);
		}
		file.close();
	}

	void FileManager::BuildDirectoryFilesMap()
	{
		//static_assert(std::is_same<T, InputDirectory>::value, "The type is not a directory");
		auto entries = FetchFilesInDirectory();
		std::vector<std::string> currentFileLines;
		std::ifstream currentFile;
		std::string currentFileLine;

		for (const auto& file : entries)
		{
			currentFile.open(file.string());

			while (std::getline(currentFile, currentFileLine))
			{
				currentFileLines.push_back(currentFileLine);
			}

			currentFile.close();
			m_directoryRawFilesMap.insert(std::pair<std::string, std::vector<std::string>>(file.string(), currentFileLines));
			currentFileLines.clear();
			currentFileLines.shrink_to_fit();
		}
	}

	std::vector<fs::path> FileManager::FetchFilesInDirectory() const
	{
		std::vector<fs::path> entries;
		for (const auto& entry : fs::directory_iterator(m_itemPath))
		{
			entries.push_back(entry.path());
		}
		return entries;
	}

	[[nodiscard]]
	std::map<std::string, std::vector<std::string>> FileManager::GetDirectoryFilesMap() const
	{
		return m_directoryRawFilesMap;
	}

	[[nodiscard]]
	std::vector<std::string> FileManager::GetFileLines() const
	{
		return m_fileRawLines;
	}
}