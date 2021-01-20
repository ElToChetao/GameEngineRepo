#include "SaveSystem.h"


bool SaveSystem::KeyExists(std::string key) {
    std::string data;
    std::ifstream file("savedData.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, data);
            if (data.find(key) == 0)
            {
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
}

bool SaveSystem::SaveExists(std::string key) {
    return KeyExists(key);
}

std::string SaveSystem::GetValue(std::string key) {
    std::string data;
    std::ifstream file("savedData.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, data);
            if (data.substr(0, data.find(':'))._Equal(key)) {
                file.close();
                data.erase(0, data.find(':') + 1);
                return data;
            }
        }
        file.close();
        return "";
    }
}