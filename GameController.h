#include <iostream>
#include "Stage.h"
#include "Player.h"
#include "Luggage.h"
#include <vector>
#include <string>

class GameController
{
  private:
    void LoadGameData();
    void InputKey();
    bool IsClear();
    void DisplayCurrentSituation();
    bool IsCorrectInputKey(char key);
    bool IsMovePlayer(int moveInput);
    Player* player;
    vector<Luggage*> Luggages;
};