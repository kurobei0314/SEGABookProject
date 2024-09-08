#include <Stage.h>

Stage::Stage(int width, int height, string stageData)
{
  stageWidth = width;
  stageHeight = height;

  for (int i = 0 ; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      string data = stageData[i + j * i];
      if (data == "#")
      {
        StageInfoVector[i].push_back(data);
      }
      else if (data == ".")
      {
        StageInfoVector[i].push_back(data);
        Goals.push_back(Goal(i, j));
      }
      else
      {
        StageInfoVector[i].push_back(" ");
      }
    }
  }
}
