#pragma once
#include"GameObject.h"
class Belt: public GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the belt's "Start Cell Position"

	CellPosition endCellPos; // here is the belt's End Cell Position
public:
	Belt(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a belt from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the belt by moving player to belt's end cell
    virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	virtual void Load(ifstream &Infile, GameObject_Type type);	// Loads and Reads the GameObject parameters from the file
	virtual ~Belt();
};

