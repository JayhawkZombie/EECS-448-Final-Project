#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>
#include <cmath>

class encryption
{
public:
	static std::string encrypt(std::string, int, int);
	static std::string decrypt(std::string, int, int);
};

#endif