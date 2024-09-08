#include "GameController.h"

using namespace std;

GameController::GameController()
{
  LoadGameData();
}

GameController::~GameController()
{
  delete stage;
  delete player;
  delete luggages;
}

void GameController::LoadGameData()
{
  int StageWidth = 8;
  int StageHeight = 5;
  vector<string> StageData = { 
    "#","#","#","#","#","#","#","#",
    "#",".",".","P"," "," "," ","#",
    "#","o","o"," "," "," "," ","#",
    "#"," "," "," "," "," "," ","#",
    "#","#","#","#","#","#","#","#"};

  stage = new Stage(StageWidth, StageHeight, StageData);
  luggages = new Luggages();

  for (int i = 0 ; i < StageHeight; i++)
  {
    for (int j = 0; j < StageWidth; j++)
    {
      char data = StageData[j + StageWidth * i][0];
      if (data == Const::PlayerCharacter) 
      {
        player = new Player(j, i);
        continue;
      }
      if (data == Const::LuggageCharacter)
      {
        luggages->AddLuggage(new Luggage(j, i));
        continue;
      }
    }
  }
}

bool GameController::IsCorrectInputKey(char key)
{
  switch(key)
  {
    case Const::InputUpKey:
    case Const::InputDownKey:
    case Const::InputRightKey:
    case Const::InputLeftKey:
      return true;
    default:
      return false;
  }
}

char GameController::InputKey()
{
  cout << "入力してください(w: 上、a:左、d:右、s: 下)" << endl;
  while (true)
  {
    char out;
    cin >> out; 
    if(IsCorrectInputKey(out)) return out;

    cout << "もう一度入力してください" << endl;
  }
}

void GameController::DisplayCurrentSituation()
{
  for (int i = 0; i < stage->GetHeight(); i++)
  {
    for (int j = 0; j < stage->GetWidth(); j++)
    {
      if (player->IsPlayerPosition(j, i))
      {
        cout << Const::PlayerCharacter << " ";
        continue;
      }
      if (luggages->IsLuggagesPosition(j, i))
      {
        cout << Const::LuggageCharacter << " ";
        continue;
      }
      cout << stage->GetMassSituation(j, i) << " ";
    }
    cout << endl;
  }
}

bool GameController::MovablePlayer(vector<int> moveInput, vector<int> currentPlayerPos)
{
  int x = moveInput[0];
  int y = moveInput[1];
  int playerPosX = currentPlayerPos[0];
  int playerPosY = currentPlayerPos[1];
  char massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
  if (massSituation == Const::WallCharacter) return false;
  if (!luggages->IsLuggagesPosition(x + playerPosX, y + playerPosY)) return true;
  
  x *= 2;
  y *= 2;
  massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
  if (massSituation == Const::WallCharacter) return false;
  if (luggages->IsLuggagesPosition(x + playerPosX, y + playerPosY)) return false;
  return true;
}

void GameController::UpdateData(vector<int> moveInput, vector<int> currentPlayerPos)
{
  int x = moveInput[0];
  int y = moveInput[1];
  int playerPosX = currentPlayerPos[0];
  int playerPosY = currentPlayerPos[1];
  char massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
  if (!luggages->IsLuggagesPosition(x + playerPosX, y + playerPosY))
  {
    player->UpdatePosition(playerPosX + x, playerPosY + y);
  }
  else
  {
    luggages->UpdateLuggagesPosition(moveInput, {playerPosX + x, playerPosY + y});
    player->UpdatePosition(playerPosX + x, playerPosY + y);
  }
}

void GameController::UpdateSituation(char inputKey)
{
  int x = 0;
  int y = 0;
  switch(inputKey)
  {
    case Const::InputUpKey:
      x = 0;
      y = -1;
      break;
    case Const::InputLeftKey:
      x = -1;
      y = 0;
      break;
    case Const::InputDownKey:
      x = 0;
      y = 1;
      break;
    case Const::InputRightKey:
      x = 1;
      y = 0;
      break;
  }
  if (MovablePlayer({x, y}, {player->GetPositionX(), player->GetPositionY()}))
  {
    UpdateData({x, y}, {player->GetPositionX(), player->GetPositionY()});
  }
}

bool GameController::IsClear()
{
  if (stage->IsMatchAllGoal(luggages->GetLuggagesPositions())) return true;
  return false;
}

int main ()
{
  GameController* controller = new GameController();
  while(true)
  {
    controller->DisplayCurrentSituation();
    controller->UpdateSituation(controller->InputKey());
    if (controller->IsClear()){
      controller->DisplayCurrentSituation();
      cout << "Congratulations!!!!!!" << endl;
      break;
    }
  }
  delete controller;
}