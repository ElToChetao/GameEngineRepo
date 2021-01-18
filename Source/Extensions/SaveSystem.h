#pragma once
#include <string>

class SaveSystem {
private:
	static bool KeyExists(std::string key);
	static std::string GetValue(std::string key);
public:
	static bool SaveExists(std::string key);

	template <typename T>
	static T Load(std::string key);

	template <typename T>
	static void Save(T data, std::string key);
 };
