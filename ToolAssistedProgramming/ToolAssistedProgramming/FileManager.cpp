#include "FileManager.hpp"

namespace File
{
	FileManager::FileManager(FileInputType type, fs::path itemPath)
		: m_itemPath(itemPath)
	{
		if (type == FileInputType::File)
		{
			OpenFile();
		}
		else
		{
			FetchFilesInDirectory();
		}
	}

	void FileManager::BuildDirectoryFilesMap()
	{
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

	void FileManager::OpenFile()
	{

	}

	void FileManager::OpenDirectory()
	{

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
}