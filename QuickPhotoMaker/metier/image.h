#pragma once
#include <string>
class Image
{
private:
	//path of the image
	std::string path;
public:
	//Constructor
	Image(const std::string& _path);

	/*
	 * sets the path of the image
	 * @param path: path of the image
	 */
	void setPath(const std::string& _path);

	//returns the path of the image
	std::string getPath() const;
};