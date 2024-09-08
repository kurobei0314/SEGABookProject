#include <iostream>
#include <vector>
#include <string>

class Goal
{
  public:
    Goal(int x, int y);
    ~Goal();
    int GetPositionX();
    int GetPositionY();
    bool IsMatchGoalPosition(int x, int y);

  private:
    int pos_x;
    int pos_y;
};