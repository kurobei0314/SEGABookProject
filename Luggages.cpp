#include "Luggages.h"

Luggages::Luggages()
{
  
}
Luggages::~Luggages()
{
  for (int i = 0; i < currentLuggages.size(); i++)
  {
    delete(currentLuggages[i]);
  }
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

void Luggages::UpdateLuggagesPosition(vector<int> moveInput, vector<int> currentLuggagePos)
{
  int currentLuggagePosX = currentLuggagePos[0];
  int currentLuggagePosY = currentLuggagePos[1];
  int moveInputX = moveInput[0];
  int moveInputY = moveInput[1];
  for (int k = 0; k < GetSize(); k++)
  {
    if (currentLuggages[k]->IsLuggagePosition(currentLuggagePosX, currentLuggagePosY))
    {
      currentLuggages[k]->UpdatePosition(currentLuggagePosX + moveInputX, currentLuggagePosY + moveInputY);
      return;
    }
  }
}

vector<vector<int>> Luggages::GetLuggagesPositions()
{
  vector<vector<int>> luggagesPositions;
  int num = GetSize();
  luggagesPositions.resize(num); 
  for (int i = 0 ; i < num; i++)
  {
    luggagesPositions[i].resize(2);
    luggagesPositions[i][0] = currentLuggages[i]->GetPositionX();
    luggagesPositions[i][1] = currentLuggages[i]->GetPositionY();
  }
  return luggagesPositions;
}