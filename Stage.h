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
    string GetMassSituation(int width, int height);
    vector< vector<string> > StageInfoVector;
    int GetWidth();
    int GetHeight();
    bool IsMatchAllGoal(vector<vector<int>> luggagePositions);

  private:
    int stageWidth;
    int stageHeight;
    vector<Goal> Goals;
};