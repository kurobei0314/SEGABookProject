#include "GameController.h"

using namespace std;

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
      string data = StageData[j + StageWidth * i];
      if (data == "P") 
      {
        player = new Player(j, i);
        continue;
      }
      if (data == "o")
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
    case 'w':
    case 's':
    case 'd':
    case 'a':
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
        cout << "P" << " ";
        continue;
      }
      if (luggages->IsLuggagesPosition(j, i))
      {
        cout << "c" << " ";
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
  string massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
  if (massSituation == "#") return false;
  if (!luggages->IsLuggagesPosition(x + playerPosX, y + playerPosY)) return true;
  
  x *= 2;
  y *= 2;
  massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
  if (massSituation == "#") return false;
  if (luggages->IsLuggagesPosition(x + playerPosX, y + playerPosY)) return false;
  return true;
}

void GameController::UpdateData(vector<int> moveInput, vector<int> currentPlayerPos)
{
  int x = moveInput[0];
  int y = moveInput[1];
  int playerPosX = currentPlayerPos[0];
  int playerPosY = currentPlayerPos[1];
  string massSituation = stage->GetMassSituation(x + playerPosX, y + playerPosY);
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
    case 'w':
      x = 0;
      y = -1;
      break;
    case 'a':
      x = -1;
      y = 0;
      break;
    case 's':
      x = 0;
      y = 1;
      break;
    case 'd':
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
  GameController GameController;
  GameController.LoadGameData();
  while(true)
  {
    GameController.DisplayCurrentSituation();
    char inputKey = GameController.InputKey();
    GameController.UpdateSituation(inputKey);
    if (GameController.IsClear()){
      GameController.DisplayCurrentSituation();
      cout << "Congratulations!!!!!!" << endl;
      break;
    }
  }
}