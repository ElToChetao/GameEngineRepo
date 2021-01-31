// Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "Game.h"
using namespace std;
int main(int argc, TCHAR* argv[])
{
    system("PAUSE");
    Game game;

    /*int gameIndex = 0;
    char exit = ' ';
    do {
        do {
            cout << "Select the game to launch! (Pong -> 0, Leafs -> 1)\n";
            cin >> gameIndex;
        } while (gameIndex < 0 || gameIndex > 1);

        if (gameIndex == 0)
        {
            system("Game.exe");
        }
        else if (gameIndex == 1)
        {
            system("Game2.exe");
        }
        system("CLS");
        cout << "Wanna select other game? (Y/N)\n";
        cin >> exit;
    } while (exit != 'N' && exit != 'n');*/
}

