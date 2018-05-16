/*!
    \file string_utils.h
    \brief String utilities definition
    \author Ivan Shynkarenka
    \date 15.05.2016
    \copyright MIT License
*/

#ifndef CPPCOMMON_STRING_STRING_UTILS_H
#define CPPCOMMON_STRING_STRING_UTILS_H

#include <algorithm>
#include <cassert>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

namespace CppCommon {

//! String utilities
/*!
    String utilities contains methods for UPPER/lower case conversions, join/split strings
    and other useful string manipulation methods.

    Thread-safe.
*/
class StringUtils
{
public:
    StringUtils() = delete;
    StringUtils(const StringUtils&) = delete;
    StringUtils(StringUtils&&) noexcept = delete;
    ~StringUtils() = delete;

    StringUtils& operator=(const StringUtils&) = delete;
    StringUtils& operator=(StringUtils&&) noexcept = delete;

    //! Is the given character blank (empty or contains only space characters)?
    /*!
        \param ch - Character to check
        \return 'true' if given character is blank, 'false' if given character is not blank
    */
    static bool IsBlank(char ch);
    //! Is the given string blank (empty or contains only space characters)?
    /*!
        \param str - String to check
        \return 'true' if given string is blank, 'false' if given string is not blank
    */
    static bool IsBlank(const std::string& str);

    //! Convert the given character to lower case
    /*!
        \param ch - Character to convert
    */
    static char ToLower(char ch);
    //! Convert the given character to UPPER case
    /*!
        \param ch - Character to convert
    */
    static char ToUpper(char ch);

    //! Convert the given string converted to lower case
    /*!
        \param str - String to convert
        \return String converted to lower case
    */
    static std::string ToLower(const std::string& str);
    //! Convert the the given string converted to UPPER case
    /*!
        \param str - String to convert
        \return String converted to UPPER case
    */
    static std::string ToUpper(const std::string& str);

    //! Convert the given string to lower case
    /*!
        \param str - String to convert
    */
    static std::string& Lower(std::string& str);
    //! Convert the given string to UPPER case
    /*!
        \param str - String to convert
    */
    static std::string& Upper(std::string& str);

    //! Trims space characters from the start
    /*!
        \param str - String to trim
    */
    static std::string& LTrim(std::string& str);
    //! Trims space characters from the end
    /*!
        \param str - String to trim
    */
    static std::string& RTrim(std::string& str);
    //! Trims space characters from the both sides
    /*!
        \param str - String to trim
    */
    static std::string& Trim(std::string& str);

    //! Is the given string contains the given character?
    /*!
        \param str - String to search in
        \param ch - Character to find
        \return 'true' if the substring was found, 'false' if the substring was not found
    */
    static bool Contains(const std::string& str, const char ch);
    //! Is the given string contains the given C-string?
    /*!
        \param str - String to search in
        \param substr - Substring to find
        \return 'true' if the substring was found, 'false' if the substring was not found
    */
    static bool Contains(const std::string& str, const char* substr);
    //! Is the given string contains the given substring?
    /*!
        \param str - String to search in
        \param substr - Substring to find
        \return 'true' if the substring was found, 'false' if the substring was not found
    */
    static bool Contains(const std::string& str, const std::string& substr);

    //! Count all occurrences of substring
    /*!
        \param str - Modifying string
        \param substr - Substring to find
        \return Count of all substring occurrences
    */
    static size_t CountAll(const std::string& str, const std::string& substr);

    //! Replace the first occurrence of substring with another substring
    /*!
        \param str - Modifying string
        \param substr - Substring to find
        \param with - Substring to replace
        \return 'true' if first occurrence of substring was found and relapsed, 'false' if the substring was not found
    */
    static bool ReplaceFirst(std::string& str, const std::string& substr, const std::string& with);
    //! Replace the last occurrence of substring with another substring
    /*!
        \param str - Modifying string
        \param substr - Substring to find
        \param with - Substring to replace
        \return 'true' if last occurrence of substring was found and relapsed, 'false' if the substring was not found
    */
    static bool ReplaceLast(std::string& str, const std::string& substr, const std::string& with);
    //! Replace all occurrences of substring with another substring
    /*!
        \param str - Modifying string
        \param substr - Substring to find
        \param with - Substring to replace
        \return 'true' if all occurrences of substring were found and relapsed, 'false' if the substring was not found
    */
    static bool ReplaceAll(std::string& str, const std::string& substr, const std::string& with);

    //! Checks the given string for specific prefix
    /*!
        \param str - String to check
        \param prefix - Prefix to check
        \return 'true' if the given string starts with the specific prefix, 'false' if the given string does not start with the specific prefix
    */
    static bool StartsWith(const std::string& str, const std::string& prefix);
    //! Checks the given string for specific suffix
    /*!
        \param str - String to check
        \param suffix - Suffix to check
        \return 'true' if the given string ends with the specific suffix, 'false' if the given string does not end with the specific suffix
    */
    static bool EndsWith(const std::string& str, const std::string& suffix);

    //! Split the string into tokens by the given delimiter character
    /*!
        \param str - String to split
        \param delimiter - Delimiter character
        \param skip_empty - Skip empty substrings flag (default is false)
        \return Vector of tokens
    */
    static std::vector<std::string> Split(const std::string& str, char delimiter, bool skip_empty = false);
    //! Split the string into tokens by the given delimiter string
    /*!
        \param str - String to split
        \param delimiter - Delimiter string
        \param skip_empty - Skip empty substrings flag (default is false)
        \return Vector of tokens
    */
    static std::vector<std::string> Split(const std::string& str, const std::string& delimiter, bool skip_empty = false);
    //! Split the string into tokens by the any character in the given delimiter string
    /*!
        \param str - String to split
        \param delimiters - Delimiters string
        \param skip_empty - Skip empty substrings flag (default is false)
        \return Vector of string tokens
    */
    static std::vector<std::string> SplitByAny(const std::string& str, const std::string& delimiters, bool skip_empty = false);

    //! Join tokens into the string
    /*!
        \param tokens - Vector of string tokens
        \param skip_empty - Skip empty tokens flag (default is false)
        \param skip_blank - Skip blank tokens flag (default is false)
        \return Joined string
    */
    static std::string Join(const std::vector<std::string>& tokens, bool skip_empty = false, bool skip_blank = false);
    //! Join tokens into the string with delimiter character
    /*!
        \param tokens - Vector of string tokens
        \param delimiter - Delimiter character
        \param skip_empty - Skip empty tokens flag (default is false)
        \param skip_blank - Skip blank tokens flag (default is false)
        \return Joined string
    */
    static std::string Join(const std::vector<std::string>& tokens, char delimiter, bool skip_empty = false, bool skip_blank = false);
    //! Join tokens into the string with delimiter C-string
    /*!
        \param tokens - Vector of string tokens
        \param delimiter - Delimiter C-string
        \param skip_empty - Skip empty tokens flag (default is false)
        \param skip_blank - Skip blank tokens flag (default is false)
        \return Joined string
    */
    static std::string Join(const std::vector<std::string>& tokens, const char* delimiter, bool skip_empty = false, bool skip_blank = false);
    //! Join tokens into the string with delimiter string
    /*!
        \param tokens - Vector of string tokens
        \param delimiter - Delimiter string
        \param skip_empty - Skip empty tokens flag (default is false)
        \param skip_blank - Skip blank tokens flag (default is false)
        \return Joined string
    */
    static std::string Join(const std::vector<std::string>& tokens, const std::string& delimiter, bool skip_empty = false, bool skip_blank = false);

    //! Converts arbitrary datatypes into string using std::ostringstream
    /*!
        \param value - Value to convert
        \return Result converted string
    */
    template <typename T>
    static std::string ToString(const T& value);
    //! Converts strings to arbitrary datatypes using std::istringstream
    /*!
        \param str - String converted into the value
        \return Result converted value
    */
    template <typename T>
    static T FromString(const std::string& str);

private:
    static char ToLowerInternal(char ch);
    static char ToUpperInternal(char ch);
};

/*! \example string_utils.cpp String utilities example */

} // namespace CppCommon

#include "string_utils.inl"

#endif // CPPCOMMON_STRING_STRING_UTILS_H
