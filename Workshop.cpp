#include "Workshop.h"

#include <iostream>
#include <fstream>
using namespace std;

Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition,WORKSHOP)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
}

Workshop::~Workshop()
{
}
void Workshop::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == WORKSHOP)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}