#include <iostream>
#include "Stage.h"
#include "Player.h"
#include "Luggages.h"
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
    bool MovablePlayer(vector<int> moveInput, vector<int> currentPlayerPos);
    void UpdateSituation(char inputKey);
    void UpdateData(vector<int> moveInput, vector<int> currentPlayerPos);
    Stage* stage;
    Player* player;
    Luggages* luggages;
};