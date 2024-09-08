class Luggage
{
  public:
    Luggage(int x, int y);
    ~Luggage();
    int GetPositionX();
    int GetPositionY();
    bool IsLuggagePosition(int x, int y);

  private:
    int pos_x;
    int pos_y;
};