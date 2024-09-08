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
    bool MovablePlayer(vector<int> moveInput, vector<int> currentPlayerPos);
    void UpdateSituation(char inputKey);
    void UpdateData(vector<int> moveInput, vector<int> currentPlayerPos);
    bool IsLuggagesPosition(int x, int y);
    void UpdateLuggagesPosition(int x, int y);
    Stage* stage;
    Player* player;
    vector<Luggage*> luggages;
};