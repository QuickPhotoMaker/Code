#pragma once
#include <string>
class Image
{
private:
	std::string path;
public:
	Image(const std::string& _path);
	void setPath(const std::string& _path);
	std::string getPath() const;
};