#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <sstream>

class SaveSystem {
private:
	static bool KeyExists(std::string key);
	static std::string GetValue(std::string key);
public:
	static bool SaveExists(std::string key);

	template <typename T>
	static T Load(std::string key) {
        if (KeyExists(key)) {
            std::string data = GetValue(key);
            T ret;
            std::stringstream iss(data);
            if (data.find("0x") != std::string::npos)
            {
                iss >> std::hex >> ret;
            }
            else
            {
                iss >> std::dec >> ret;
            }

            if (iss.fail())
            {
                std::cout << "Convert error: cannot convert string '" << data << "' to value" << std::endl;
                return T();
            }
            return ret;
        }
        return T();
    };

	template <typename T>
	static void Save(T data, std::string key) {
		if (!KeyExists(key)) {
			std::ofstream file;
			file.open("savedData.txt", std::ios_base::app);
			file << key + ':';
			file << data;
			file << '\n';
			file.close();
		}
	};
 };
