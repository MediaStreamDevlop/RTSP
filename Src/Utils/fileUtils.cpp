#include "Utils/fileUtils.h"

unsigned int getFileSize(const std::string& fileName)
{
    std::ifstream in(fileName);
	in.seekg(0, std::ios::end);
	int ps = in.tellg();
    std::cout << "File size: " << ps << std::endl;
	in.close();
    return (unsigned int) ps;
}
