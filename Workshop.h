#pragma once
#include "GameObject.h"
class Workshop : public GameObject
{
public:
	Workshop(const CellPosition &workshopPosition);
	virtual void Draw(Output *pOut) const; // Draws workshop

	virtual void Apply(Grid *pGrid, Player *pPlayer);			// Applys the effect of the workshop
	virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	~Workshop();
};
