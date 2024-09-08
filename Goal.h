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

  private:
    int pos_x;
    int pos_y;
};