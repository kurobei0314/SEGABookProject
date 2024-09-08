#include "Goal.h"

Goal::Goal(int x, int y)
{
  pos_x = x;
  pos_y = y;
}

Goal::~Goal(){

}

int Goal::GetPositionX()
{
  return pos_x;
}

int Goal::GetPositionY()
{
  return pos_y;
}

bool Goal::IsMatchGoalPosition(int x, int y)
{
  return (x == pos_x && y == pos_y);
}