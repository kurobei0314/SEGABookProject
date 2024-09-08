#include "Luggages.h"

Luggages::Luggages()
{
  
}
Luggages::~Luggages()
{

}

void Luggages::AddLuggage(Luggage* luggage)
{
  currentLuggages.push_back(luggage);
}

int Luggages::GetSize()
{
  return currentLuggages.size();
}

bool Luggages::IsLuggagesPosition(int x, int y)
{
  for (int i = 0; i < GetSize(); i++)
  {
    if (currentLuggages[i]->IsLuggagePosition(x, y))
    {
      return true;
    }
  }
  return false;
}

void Luggages::UpdateLuggagesPosition(int x, int y)
{
  for (int k = 0; k < GetSize(); k++)
  {
    if (currentLuggages[k]->IsLuggagePosition(x, y))
    {
      currentLuggages[k]->UpdatePosition(x, y);
      return;
    }
  }
}