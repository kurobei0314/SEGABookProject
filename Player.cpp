#include "Player.h"
using namespace std;

Player::Player(int x, int y)
{
  UpdatePosition(x, y);
}

int Player::GetPositionX()
{
  return pos_x;
}

int Player::GetPositionY()
{
  return pos_y;
}

bool Player::IsPlayerPosition(int x, int y)
{
  return (pos_x == x && pos_y == y);
}

void Player::UpdatePosition(int x, int y)
{
  pos_x = x;
  pos_y = y;
}