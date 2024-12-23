#pragma once
#include "GameObject.h"
class Flag :public GameObject
{
public:
	Flag(const CellPosition & flagposition); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a flag in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	virtual void Load(ifstream &Infile, GameObject_Type type); // Loads and Reads the GameObject parameters from the file
	virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	virtual ~Flag(); // Virtual destructor
};