#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>

enum eLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
};

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	int getLevel(std::string level);
public:
	void complain(std::string level);
};

#endif
