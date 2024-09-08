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