#include <iostream>
#include "Stage.h"
#include "Player.h"
#include "Luggage.h"
#include <vector>
#include <string>

class GameController
{
  public:
    void LoadGameData();
    char InputKey();
    bool IsClear();
    void DisplayCurrentSituation();
    bool IsCorrectInputKey(char key);
    bool IsMovePlayer(int moveInput);
    void UpdateSituation(char inputKey);
    Stage* stage;
    Player* player;
    vector<Luggage*> luggages;
};