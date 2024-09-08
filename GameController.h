#include <iostream>
#include <Stage.h>
#include <Player.h>
#include <Luggage.h>
#include <vector>
#include <string>

class GameController
{
  private:
    void LoadGameData();
    void InputKey();
    bool IsClear();
    void DisplayCurrentSituation();
    Player* player;
    vector<Luggage*> Luggages;
};