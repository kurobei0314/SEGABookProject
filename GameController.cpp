#include "GameController.h"

using namespace std;

void LoadGameData()
{
  int StageWidth = 8;
  int StageHeight = 5;
  vector<string> StageData = { 
    "#","#","#","#","#","#","#","#",
    "#",".",".","P"," "," "," ","#",
    "#","o","o"," "," "," "," ","#",
    "#"," "," "," "," "," "," ","#",
    "#","#","#","#","#","#","#","#"};

  Stage* stage = new Stage(StageWidth, StageHeight, StageData);
  Player* player;
  vector<Luggage*> Luggages;

  for (int i = 0 ; i < StageHeight; i++)
  {
    for (int j = 0; j < StageWidth; j++)
    {
      string data = StageData[j + j * i];
      if (data == "P") 
      {
        player = new Player(StageWidth, StageHeight);
        continue;
      }
      if (data == "o")
      {
        Luggage* luggage = new Luggage(StageWidth, StageHeight);
        Luggages.push_back(luggage);
        continue;
      }
    }
  }
}

bool IsCorrectInputKey(char key)
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

char InputKey()
{
  cout << "入力してください(W: 上、A:左、D:右、S: 下)" << endl;
  while (true)
  {
    char out;
    cin >> out; 
    if(IsCorrectInputKey(out)) return out;

    cout << "もう一度入力してください" << endl;
  }
}

void DisplayCurrentSituation()
{

}

bool IsMovePlayer(int moveInput)
{
  return true;
}

void UpdateSituation(char inputKey)
{
  switch(inputKey)
  {
    case 'w':
      if (IsMovePlayer(1))
      break;
  }
}

bool IsClear()
{
  return true;
}

int main ()
{
  LoadGameData();
  while(true)
  {
    DisplayCurrentSituation();
    char inputKey = InputKey();
    UpdateSituation(inputKey);
    if (IsClear()) break;
  }
}