#include "daoImage.h"

//saves the image path
void DAOImage::save(const Image& image)
{
	std::ofstream file("paths.txt", std::ios::app);
	if (!file.is_open())
		throw "Erreur lors de l'ouverture du fichier";
	file << image.getPath() << '\n';
	file.close();
}

//loads the image path
void DAOImage::load(Images& images)
{
	std::ifstream file("paths.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			std::string path;
			std::getline(file, path, '\n');
			Image image(path);
			images.add(image);
		}
	}
	file.close();
}