#pragma once
#include <string>
using namespace std;
class Entity
{
public:
	Entity();
	string tag;
	string name;
	bool isActive;

	void setActive(bool b) { isActive = b; }
	void setTag(string tag) { this->tag = tag; }
};

