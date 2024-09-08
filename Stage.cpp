#include "Stage.h"
#include "Const.h"

Stage::Stage(int width, int height, vector<string> stageData)
{
  stageWidth = width;
  stageHeight = height;

  StageInfoVector.resize(height); 
  for (int i = 0 ; i < height; i++)
  {
    StageInfoVector[i].resize(width);
  }

  for (int i = 0 ; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      char data = stageData[j + width * i][0];
      if (data == Const::WallCharacter)
      {

        StageInfoVector[i][j] = data;
      }
      else if (data == Const::GoalCharacter)
      {
        StageInfoVector[i][j] = data;
        Goals.push_back(Goal(j, i));
      }
      else
      {
        StageInfoVector[i][j] = Const::EmptyCharacter;
      }
    }
  }
}

char Stage::GetMassSituation(int width, int height)
{
  return StageInfoVector[height][width];
}

int Stage::GetWidth()
{
  return stageWidth;
}

int Stage::GetHeight()
{
  return stageHeight;
}

bool Stage::IsMatchAllGoal(vector<vector<int>> luggagePositions)
{
  int luggageNum = luggagePositions.size();
  int goalNum = Goals.size();
  int matchGoalPositionNum = 0;
  for (int i = 0 ; i < luggageNum ; i++)
  {
    for (int j = 0; j < goalNum ; j++)
    {
      int x = luggagePositions[i][0];
      int y = luggagePositions[i][1];
      if (Goals[j].IsMatchGoalPosition(x, y))
      {
        matchGoalPositionNum++;
        break;
      }
    }
  }
  return (matchGoalPositionNum == goalNum) ? true : false;
}
