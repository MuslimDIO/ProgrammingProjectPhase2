#pragma once
#include "GameObject.h"
class Antenna :public GameObject
{
public:
	Antenna(const CellPosition & antennaPosition);
	virtual void Draw(Output* pOut) const; // Draws an antenna

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns
    virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
    virtual void Load(ifstream &Infile, GameObject_Type type); // Loads and Reads the GameObject parameters from the file
	virtual ~Antenna();
};

