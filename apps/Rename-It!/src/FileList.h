#pragma once
#include "FileName.h"

/**
 * Contains a list of file names.
 */
class CFileList
{
// Attributes
public:
	int GetFileCount() const {
		return (int) m_vfnFiles.size();
	}

	const CFileName& GetFile(int nIndex) const {
		return m_vfnFiles.at(nIndex);
	}

// Basic list operations
	/**
	 * Add a file to the end of the files list.
	 * @param[in] fnFileName	The file name of the file to be renamed.
	 * @return The index of the added file.
	 */
	int AddFile(const CFileName& fnFileName)
	{
		m_vfnFiles.push_back(fnFileName);
		return (int) m_vfnFiles.size() - 1;
	}

	/**
	 * Overloaded method that constructs the CFileName from the path.
	 * @param[in] strFileName	Path to the file or folder to be renamed.
	 * @return The index of the added file.
	 */
	inline int AddFile(const CString& strFileName) {
		return AddFile(CFileName(strFileName));
	}

	/**
	 * Insert a file at a specific position in the list.
	 * @param[in] fnFileName	The file name of the file to be renamed.
	 * @param[in] nIndex		Index position where the file should be insert (0 means first element of the list).
	 */
	void InsertFile(int nIndex, const CFileName& fnFileName)
	{
		if (nIndex == (int) m_vfnFiles.size())
			AddFile(fnFileName);
		else if (nIndex >= (int) m_vfnFiles.size())
			throw out_of_range("Index is out of range.");
		else
			m_vfnFiles.insert(m_vfnFiles.begin() + nIndex, fnFileName);
	}

	/**
	 * Overloaded method that constructs the CFileName from the path.
	 * @param[in] strFileName	Path to the file or folder to be renamed.
	 * @param[in] nIndex		See InsertFile above.
	 */
	inline void InsertFile(int nIndex, const CString& strFileName) {
		return InsertFile(nIndex, CFileName(strFileName));
	}

	/**
	 * Remove a file from the list of files to be renamed.
	 * @param[in] nIndex		Index of the file to remove.
	 */
	void RemoveFile(int nIndex) {
		if (nIndex < 0 || nIndex >= (int) m_vfnFiles.size())
			throw out_of_range("Index is out of range.");
		else
			m_vfnFiles.erase(m_vfnFiles.begin() + nIndex);
	}

	const CFileName& operator[](int nIndex) const {
		return m_vfnFiles.at(nIndex);
	}

// Implementation
private:
	vector<CFileName> m_vfnFiles;
};
