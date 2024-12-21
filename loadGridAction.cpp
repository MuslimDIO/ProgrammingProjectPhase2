#include "loadGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;



LoadGridAction::LoadGridAction(ApplicationManager *pApp) : Action(pApp)
{
}
void LoadGridAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();
    pOut->PrintMessage("Enter the file name to load the grid");
    string a_fileName = pIn->GetSrting(pOut);
    _fileName = a_fileName;
    pOut->PrintMessage("LOADING GRID.......");
}

void LoadGridAction :: Execute(){
ReadActionParameters();
Grid *pGrid = pManager->GetGrid();
ifstream l_inFile;
l_inFile.open(_fileName+".txt",ios::in);

  // l_outFile<<"start file"<<endl;
  for (uint8_t i = 0; i <= ROTATING_GEAR; i++)
  {
    pGrid->LoadAll(l_inFile, (GameObject_Type)i);
  }
  // l_outFile<<"END file"<<endl;
  l_inFile.close();

  Output *pOut = pGrid->GetOutput();
  pOut->PrintMessage("Grid Loaded successfully");


}

LoadGridAction::~LoadGridAction()
{
}