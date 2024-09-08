#include <iostream>

class Player
{
  public:
    Player(int x, int y);
    ~Player();
    int GetPositionX();
    int GetPositionY();
    bool IsPlayerPosition(int x, int y);

  private:
    int pos_x;
    int pos_y;
};