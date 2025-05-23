#pragma once

#include "Grid.h"
enum GameObject_Type
{
	FLAG,
	WATERPIT,
	DANGERZONE,
	BELT,
	WORKSHOP,
	ANTENNA,
	ROTATING_GEAR
}; // An enumeration for all the types of GameObjects
// Base Class for All Game Objects ( Belts, danger zones, .. )
class GameObject
{
	const GameObject_Type _type;

protected:
	CellPosition position; // The current cell position of the GameObject

public:
	GameObject(const CellPosition &pos, GameObject_Type a_type); // Constructor for initializing data members

	CellPosition GetPosition() const; // A Getter for position

	// ============ Virtual Functions ============

	virtual void Draw(Output *pOut) const = 0; // Draws the game object in the window in his position cell
											   // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid *pGrid, Player *pPlayer) = 0; // Applys the effect of the GameObject on the passed Player
														  // (The effect depends on the GameObject type, so virtual)
														  // For example, applying a belt is by moving player to the
														  // end of the belt, and so on

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class
	GameObject_Type getObjType() const;
	/// TODO::Decide the parameters that you should pass to each function
	// Uncomment those functions and implement them in all the derived classes
	virtual void Save(ofstream &OutFile, GameObject_Type) = 0; // Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, GameObject_Type) = 0;	// Loads and Reads the GameObject parameters from the file

	virtual ~GameObject(); // Virtual destructor
};
