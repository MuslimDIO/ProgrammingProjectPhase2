#pragma once
#include "GameObject.h"
class DangerZone : public GameObject
{
public:
	DangerZone(const CellPosition &dangerZonePosition);
	virtual void Draw(Output *pOut) const; // Draws a danger zone in the cell

	virtual void Apply(Grid *pGrid, Player *pPlayer);			// Applys the effect of the danger zone by reducing the robot's health by 1
	virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, GameObject_Type type);	// Loads and Reads the GameObject parameters from the file
	virtual ~DangerZone();
};
