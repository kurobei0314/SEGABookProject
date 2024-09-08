#include <iostream>
#include <vector>
#include <string>
#include "Stage.h"
#include "Player.h"
#include "Luggages.h"
#include "Const.h"

class GameController
{
  public:
    void LoadGameData();
    void DisplayCurrentSituation();
    void UpdateSituation(char inputKey);
    bool IsClear();
    char InputKey();

  private:
    bool IsCorrectInputKey(char key);
    bool MovablePlayer(vector<int> moveInput, vector<int> currentPlayerPos);
    void UpdateData(vector<int> moveInput, vector<int> currentPlayerPos);
    Stage* stage;
    Player* player;
    Luggages* luggages;
};