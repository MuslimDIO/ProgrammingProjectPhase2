#pragma once
#include "GameObject.h"
class RotatingGear : public GameObject
{
	bool isClockWise; // if it is true then direction is clockwise, if it is false then direction is anticlockwise
public:
	RotatingGear(const CellPosition & gearposition,bool clockwise  );
	RotatingGear(const CellPosition & gearposition ); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a rotating gear in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	bool GetisClockWise() const; // Getter for the direction
	void setIsClockWise(bool a_isClockWise); // Setter for the direction
	virtual void Load(ifstream &Infile, GameObject_Type type); // Loads and Reads the GameObject parameters from the file
	
	virtual void Save(ofstream &OutFile, GameObject_Type type); // Saves the GameObject parameters to the file
	virtual ~RotatingGear();
};

