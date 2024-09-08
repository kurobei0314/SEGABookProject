#include "Stage.h"

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
      string data = stageData[j + width * i];
      if (data == "#")
      {

        StageInfoVector[i][j] = data;
      }
      else if (data == ".")
      {
        StageInfoVector[i][j] = data;
        Goals.push_back(Goal(i, j));
      }
      else
      {
        StageInfoVector[i][j] = ' ';
      }
    }
  }
}

string Stage::GetMassSituation(int width, int height)
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
