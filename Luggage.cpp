#include "Luggage.h"

Luggage::Luggage(int x, int y)
{
  UpdatePosition(x, y);
}

int Luggage::GetPositionX()
{
  return pos_x;
}

int Luggage::GetPositionY()
{
  return pos_y;
}

bool Luggage::IsLuggagePosition(int x, int y)
{
  return (pos_x == x && pos_y == y);
}

void Luggage::UpdatePosition(int x, int y)
{
  pos_x = x;
  pos_y = y;
}