#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

class Convoluted
{
private:
	std::list<std::pair<std::string, std::string>> unsortedA;
	std::list<std::pair<std::string, int>> positionRedP;
public:
	Convoluted(std::string, std::string);
	void readFiles(std::string, std::string);
	void display();
	void loop();
};