#include "convoluted.h"

Convoluted::Convoluted(std::string start, std::string rest)
{
	readFiles(start, rest);
}

void Convoluted::readFiles(std::string startPath, std::string restPath)
{
	std::ifstream firsthandle{ startPath };
	std::string text;
	if (std::getline(firsthandle, text)) {
		std::stringstream ss(text);
		std::pair<std::string, int> b;
		std::getline(ss, b.first, ':');
		b.second = 0;
		positionRedP.push_front(b);
	}
	firsthandle.close();

	std::ifstream resthandle{ restPath };
	while (std::getline(resthandle, text)) {
		std::stringstream ss(text);
		std::pair<std::string, std::string> a;
		std::getline(ss, a.first, ':');
		std::getline(ss, a.second, ':');
		unsortedA.push_back(a);
	}
	resthandle.close();
}

void Convoluted::display()
{
	for (const auto i : unsortedA) {
		std::cout << i.first << " " << i.second << std::endl;
	}

	for (const auto d : positionRedP) {
		std::cout << d.first << " " << d.second << std::endl;
	}
}

void Convoluted::loop()
{

}