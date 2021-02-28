#include "FileManager.hpp"

namespace File
{
	/*template class FileManager<InputFile>;
	template class FileManager<InputDirectory>;*/

	template<typename T>
	FileManager<T>::FileManager(fs::path itemPath)
		: m_itemPath(itemPath)
	{
		if constexpr(std::is_same<T, InputFile>::value)
		{
			BuildFileLines();
		}
		if constexpr(std::is_same<T, InputDirectory>::value)
		{
			BuildDirectoryFilesMap();
		}
	}

	template<typename T>
	void FileManager<T>::BuildFileLines()
	{
		static_assert(std::is_same<T, InputFile>::value, "The type is not a file");
		std::ifstream file;
		std::string fileLine;

		file.open(m_itemPath.string());
		while (std::getline(file, fileLine))
		{
			m_fileRawLines.push_back(fileLine);
		}
		file.close();
	}

	template<typename T>
	void FileManager<T>::BuildDirectoryFilesMap()
	{
		static_assert(std::is_same<T, InputDirectory>::value, "The type is not a directory");
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

	template<typename T>
	std::vector<fs::path> FileManager<T>::FetchFilesInDirectory() const
	{
		std::vector<fs::path> entries;
		for (const auto& entry : fs::directory_iterator(m_itemPath))
		{
			entries.push_back(entry.path());
		}
		return entries;
	}

	template<typename T>
	[[nodiscard]]
	std::map<std::string, std::vector<std::string>> FileManager<T>::GetDirectoryFilesMap() const
	{
		return m_directoryRawFilesMap;
	}

	template<typename T>
	[[nodiscard]]
	std::vector<std::string> FileManager<T>::GetFileLines() const
	{
		return m_fileRawLines;
	}
}