#pragma once
#include <string>
class Image
{
private:
	std::string path;
public:
	Image(const std::string& _path);
	Image(const Image& image);
	const Image& operator=(const Image& image);
	void copy(const Image& image);
	void setPath(const std::string& value);
	std::string getPath() const;
};
std::ostream& operator<<(std::ostream& stream, const Image& image);