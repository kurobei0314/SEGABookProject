#include <vector>
#include <iostream>
#include "Luggage.h"
using namespace std;

class Luggages
{
  public:
    Luggages();
    ~Luggages();
    void AddLuggage(Luggage* luggage);
    int GetSize();
    bool IsLuggagesPosition(int x, int y);
    void UpdateLuggagesPosition(int x, int y);

  private:
    vector<Luggage*> currentLuggages;
};