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
    void UpdateLuggagesPosition(vector<int> moveInput, vector<int> currentLuggagesPos);
    vector<vector<int>> GetLuggagesPositions();

  private:
    vector<Luggage*> currentLuggages;
};