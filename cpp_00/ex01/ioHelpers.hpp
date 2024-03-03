#ifndef IOHELPERS_HPP
# define IOHELPERS_HPP

# define ADD_STR "ADD"
# define SEARCH_STR "SEARCH"
# define Q_STR "EXIT"

# include <string>

int isInvalidNumber(const std::string& number);
void promptInput(const std::string &prompt, std::string &var, int (*validFunc)(const std::string &number) = nullptr);
std::string formatColumn(const std::string input);

#endif