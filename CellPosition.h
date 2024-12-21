#pragma once
#include "DEFS.h"

/* 
 * MISRA-C:2012 Deviation Justification
 * Rule: 20.9 - A macro should not be used if an inline function can be used instead.
 * Deviation Type: Required
 * Justification:
 *    The macro `VALIDATE_CELL` is used to simplify repetitive validation logic across the 
 *    codebase, specifically to check if a given cell position is valid. Using an inline 
 *    function in this case would stop it effectivenss as this macro is used to return if not valid
 *   Mitigation Measures:
 *    - The macro usage is limited to validation logic.
 *    - Unit testing ensures correct behavior of the validation logic.
 * Reviewer: Omar Walid
 * Approval: 
 */

#define VALIDATE_CELL(CELL)    \
	if (!CELL##.IsValidCell()) \
	return

/* 
 * MISRA-C:2012 Deviation Justification
 * Rule: 20.9 - A macro should not be used if an inline function can be used instead.
 * Deviation Type: Required
 * Justification:
 *    The macro `VALIDATE_CELL_NUM` is used to enforce a specific rule that the first cell 
 *    (cell number 1) cannot be used in certain operations. This check is lightweight, 
 *    context-specific, and consistently applied across the codebase using this macro. 
 *     Using an inline 
 *    function in this case would stop it effectivenss as this macro is used to return if not valid
 * Mitigation Measures:
 *    - The macro usage is limited to enforcing cell number rules.
 *    - Unit tests verify that invalid cell numbers are correctly rejected.
 *    - Static analysis tools confirm compliance with other rules.
 * Reviewer: Omar Walid
 * Approval: 
 */

#define VALIDATE_CELL_NUM(CELL)   \
	if (CELL##.GetCellNum() == 1) \
	return
class CellPosition
{
	int vCell; // the vertical cell number: starts from 0 to NumVerticalCells - 1
	int hCell; // the horizontal cell number: starts from 0 to NumHorizontalCells - 1

public:
	CellPosition (); // Initializes the cell to (-1,-1) indicating not initialized with valid values
	CellPosition (int v, int h); // Sets vCell and hCell if valid
	CellPosition (int cellNum);  // Sets vCell and hCell from the passed cellNum if valid

	// Note: this class does NOT deal with real coordinates, it deals with the "vCell", "hCell" and "cellNum" instead

	// assuming NumVerticalCells = 5 and NumHorizontalCells = 11 
	// Cell Numbers (CellNum) should be from 1 to 55
	// Numbered from [left-to-right] [bottom-up], as follows:

	// hCell (right):   0    1   ...   10
	// vCell (below):
	//   0             C45  C46  ...  C55
	//   1             C34  C35  ...  C44
	//  ...            ...  ...  ...  ...
	//   3             C12  C13  ...  C22
	//   4             C1   C2   ...  C11

	// In the Grid above, C13 has vCell = 3 and hCell = 1
	

	
	bool SetVCell(int v); 		//DONE

	bool SetHCell(int h); 		//DONE

	int VCell() const; // The getter of vCell
	int HCell() const; // The getter of hCell


	bool IsValidCell() const;		//DONE
		
	int GetCellNum() const;   		//DONE

	static int GetCellNumFromPosition(const CellPosition & cellPosition);  		//DONE

	static CellPosition GetCellPositionFromNum(int cellNum);		//DONE

    void AddCellNum(int addedNum, Direction direction);		//DONE

};

