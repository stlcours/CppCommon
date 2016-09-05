/*!
    \file directory.h
    \brief Filesystem directory wrapper definition
    \author Ivan Shynkarenka
    \date 30.08.2016
    \copyright MIT License
*/

#ifndef CPPCOMMON_FILESYSTEM_DIRECTORY_H
#define CPPCOMMON_FILESYSTEM_DIRECTORY_H

#include "filesystem/directory_iterator.h"
#include "filesystem/file.h"
#include "filesystem/symlink.h"

namespace CppCommon {

//! Filesystem directory
/*!
    Filesystem directory wraps directory management operations (create,
    remove, iterate).

    Not thread-safe.
*/
class Directory : public Path
{
public:
    //! Default directory attributes (Normal)
    static const Flags<FileAttributes> DEFAULT_ATTRIBUTES;
    //! Default directory permissions (IRUSR | IWUSR | IXUSR | IRGRP | IXGRP | IROTH | IXOTH)
    static const Flags<FilePermissions> DEFAULT_PERMISSIONS;

    Directory() : Path() {}
    Directory(const Path& path) : Path(path) {}
    Directory(const Directory&) = default;
    Directory(Directory&&) noexcept = default;
    ~Directory() = default;

    Directory& operator=(const Path& path)
    { Assign(path); return *this; }
    Directory& operator=(const Directory&) = default;
    Directory& operator=(Directory&&) noexcept = default;

    //! Is directory exists?
    bool IsDirectoryExists() const;
    //! Is directory empty?
    bool IsDirectoryEmpty() const;

    //! Get the directory begin iterator
    DirectoryIterator begin() const;
    //! Get the directory end iterator
    DirectoryIterator end() const;

    //! Get the directory recursive begin iterator
    DirectoryIterator rbegin() const;
    //! Get the directory recursive end iterator
    DirectoryIterator rend() const;

    //! Get all entries (directories, filters, symbolic links) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Entries collection
    */
    std::vector<Path> GetEntries(const std::string& filter = "");
    //! Recursively get all entries (directories, filters, symbolic links) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Entries collection
    */
    std::vector<Path> GetEntriesRecurse(const std::string& filter = "");

    //! Get all directories (including symbolic link directories) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Directories collection
    */
    std::vector<Directory> GetDirectories(const std::string& filter = "");
    //! Recursively get all directories (including symbolic link directories) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Directories collection
    */
    std::vector<Directory> GetDirectoriesRecurse(const std::string& filter = "");

    //! Get all files (including symbolic link files) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Files collection
    */
    std::vector<File> GetFiles(const std::string& filter = "");
    //! Recursively get all files (including symbolic link files) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Files collection
    */
    std::vector<File> GetFilesRecurse(const std::string& filter = "");

    //! Get all symbolic links (including symbolic link directories) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Symbolic links collection
    */
    std::vector<Symlink> GetSymlinks(const std::string& filter = "");
    //! Recursively get all symbolic links (including symbolic link directories) in the current directory
    /*!
        \param filter - Filter regular expression (default is "")
        \return Symbolic links collection
    */
    std::vector<Symlink> GetSymlinksRecurse(const std::string& filter = "");

    //! Create directory from the given path
    /*!
        \param path - Directory path
        \param attributes - Directory attributes (default is Directory::DEFAULT_ATTRIBUTES)
        \param permissions - Directory permissions (default is Directory::DEFAULT_PERMISSIONS)
        \return Created directory
    */
    static Directory Create(const Path& path, const Flags<FileAttributes>& attributes = Directory::DEFAULT_ATTRIBUTES, const Flags<FilePermissions>& permissions = Directory::DEFAULT_PERMISSIONS);
    //! Create full directory tree of the given path
    /*!
        \param path - Directory path
        \param attributes - Directory attributes (default is Directory::DEFAULT_ATTRIBUTES)
        \param permissions - Directory permissions (default is Directory::DEFAULT_PERMISSIONS)
        \return Created full directory tree
    */
    static Directory CreateTree(const Path& path, const Flags<FileAttributes>& attributes = Directory::DEFAULT_ATTRIBUTES, const Flags<FilePermissions>& permissions = Directory::DEFAULT_PERMISSIONS);

    //! Swap two instances
    void swap(Directory& directory) noexcept;
    friend void swap(Directory& directory1, Directory& directory2) noexcept;
};

/*! \example filesystem_symlink.cpp Filesystem symlink wrapper example */

} // namespace CppCommon

#include "directory.inl"

#endif // CPPCOMMON_FILESYSTEM_DIRECTORY_H
