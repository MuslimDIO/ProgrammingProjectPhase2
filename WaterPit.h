#pragma once
#include "GameObject.h"
class WaterPit:public GameObject
{
public:
	WaterPit(const CellPosition & waterPitPosition); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a water pit in the cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the waterPit by killing the robot instantly and ending the game
   virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
   virtual void Load(ifstream &Infile, GameObject_Type type); // Loads and Reads the GameObject parameters from the file
	virtual ~WaterPit();
};

