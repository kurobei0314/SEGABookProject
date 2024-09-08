#include <iostream>
#include <string>
#include <vector>
#include "Goal.h"
using namespace std;

class Stage
{
  public:
    Stage(int width, int height, vector<string> stageData);
    ~Stage();
    char GetMassSituation(int width, int height);
    vector< vector<char> > StageInfoVector;
    int GetWidth();
    int GetHeight();
    bool IsMatchAllGoal(vector<vector<int>> luggagePositions);

  private:
    int stageWidth;
    int stageHeight;
    vector<Goal> Goals;
};