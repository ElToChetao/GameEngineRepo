#pragma once
#include <iostream>
#include "Game.h"
#include "Game2.h"
using namespace std;
int main(int argc, char* args[])
{
    int gameIndex = 0;
    char exit = ' ';
    do {
        do {
            cout << "Select the game to launch! (Pong -> 0, Leafs -> 1)\n";
            cin >> gameIndex;
        } while (gameIndex < 0 || gameIndex > 1);

        if (gameIndex == 0)
        {
            Game game;
        }
        else if (gameIndex == 1)
        {
            Game2 game;
        }
        system("CLS");
        cout << "Wanna select other game? (Y/N)\n";
        cin >> exit;
    } while (exit != 'N' && exit != 'n');
    return 0;
}

