#include <iostream>
#include <string>
#include <vector>
#include <Goal.h>
using namespace std;

class Stage
{
  public:
    Stage(int width, int height, string stageData);
    ~Stage();
    int stageWidth;
    int stageHeight;
    vector<vector<string>> StageInfoVector;
    vector<Goal> Goals;
};