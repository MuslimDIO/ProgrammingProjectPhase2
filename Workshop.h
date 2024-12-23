#pragma once
#include "GameObject.h"
class Workshop : public GameObject
{
public:
	Workshop(const CellPosition &workshopPosition);
	virtual void Draw(Output *pOut) const; // Draws workshop

	virtual void Apply(Grid *pGrid, Player *pPlayer);			// Applys the effect of the workshop
	virtual void Load(ifstream &Infile, GameObject_Type type); // Loads and Reads the GameObject parameters from the file
	virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	~Workshop();
};
