#include <GameController.h>

using namespace std;

void LoadGameData()
{
  int StageWidth = 8;
  int StageHeight = 5;
  string StageData[8 * 5] = { 
    "#","#","#","#","#","#","#","#",
    "#",".",".","P"," "," "," ","#",
    "#","o","o"," "," "," "," ","#",
    "#"," "," "," "," "," "," ","#",
    "#","#","#","#","#","#","#","#"};

  Stage* stage = new Stage(StageWidth, StageHeight, StageData[0]);
  Player* player;
  vector<Luggage*> Luggages;

  for (int i = 0 ; i < StageHeight; i++)
  {
    for (int j = 0; j < StageWidth; j++)
    {
      string data = StageData[i + j * i];
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

void InputKey()
{
  
}

void DisplayCurrentSituation()
{

}

bool IsClear()
{

}

int main ()
{

  LoadGameData();
  while(true)
  {
    DisplayCurrentSituation();
    InputKey();
    if (IsClear()) break;
  }
}