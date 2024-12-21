#include "saveGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;

void SaveGrid::ReadActionParameters()
{
  Grid *pGrid = pManager->GetGrid();
  Output *pOut = pGrid->GetOutput();
  Input *pIn = pGrid->GetInput();
  pOut->PrintMessage("Enter the file name to save the grid");
  string fileName = pIn->GetSrting(pOut);
  _fileName = fileName;
  pOut->PrintMessage("SAVING GRID.......");
}
void SaveGrid::Execute()
{
  ReadActionParameters();
  Grid *pGrid = pManager->GetGrid();
  ofstream l_outFile;
  l_outFile.open(_fileName + ".txt", ios::out);
  // l_outFile<<"start file"<<endl;
  for (uint8_t i = 0; i <= ROTATING_GEAR; i++)
  {
    pGrid->SaveAll(l_outFile, (GameObject_Type)i);
  }
  // l_outFile<<"END file"<<endl;
  l_outFile.close();

  Output *pOut = pGrid->GetOutput();
  pOut->PrintMessage("Grid saved successfully");
}
SaveGrid::SaveGrid(ApplicationManager *pApp) : Action(pApp)
{
}
SaveGrid::~SaveGrid()
{
}