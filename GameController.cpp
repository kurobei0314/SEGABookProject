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
        Luggage* luggage = new Luggage(j, i);
        luggages.push_back(luggage);
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
      string posSituation = "";
      if (player->IsPlayerPosition(j, i))
      {
        cout << "P" << " ";
        posSituation = "P";
        continue;
      }
      for (int k = 0; k < luggages.size(); k++)
      {
        if (luggages[k]->IsLuggagePosition(j, i))
        {
          cout << "c" << " ";
          posSituation = "c";
          break;
        }
      }
      if (posSituation != "") continue;
      cout << stage->GetMassSituation(j, i) << " ";
    }
    cout << endl;
  }
}

bool GameController::IsMovePlayer(int moveInput)
{
  return true;
}

void GameController::UpdateSituation(char inputKey)
{
  switch(inputKey)
  {
    case 'w':
      if (IsMovePlayer(1))
      break;
  }
}

bool GameController::IsClear()
{
  return true;
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
      break;
    }
  }
}