// Copyright (c) 2025 Thomas Duggan
// This work is licensed under CC BY-SA 4.0


#include "ThreeDBingoBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


///////////////////////////// My Code ////////////////////////////////////

// Note: all instances of BOARD_DIM get replaced with 5

// Should return true if the indices i, j and k correspond to the 
// centre square and false otherwise.
bool CentreSquare(int i, int j, int k)
{
    if (i == 2 && j == 2 && k == 2){
        return true;
    }

    else{
        return false;
    }
}

// Should return true if all board numbers are valid (according to usual Bingo rules)
// on the 3D Bingo board and false otherwise
bool BoardNumbersValid(const ThreeDBingoBoard board)
{
	for(int x_val = 0; x_val < 5; ++x_val)
	{
		for(int y_val = 0; y_val < 5; ++y_val)
		{
			for(int z_val = 0; z_val < 5; ++z_val)
			{

				// cout << z_val << "\n";
				// cout << board[x_val][y_val][z_val].number << "\n";	//FOR TESTING ONLY
				// cout << "\n";

				if (z_val == 0 || z_val == 5 || z_val == 10 || z_val == 15 || z_val == 20)
				{

				vector<int> legality {};
				bool legal = false;

					for(int valid_value = 1; valid_value <= 15; ++valid_value)
					{
						if (board[x_val][y_val][z_val].number != valid_value)
						{
							legality.push_back(0);
						}
						else{
							legality.push_back(1);
						}
					}

					for (int i = 0; i <= legality.size(); ++i){
						if (legality[i] == 1){
							legal = true;
						}
					}
					
					if (legal != true){
						return false;
					}
				}

				if (z_val == 1 || z_val == 6 || z_val == 11 || z_val == 16 || z_val == 21)
				{

				vector<int> legality {};
				bool legal = false;

					for(int valid_value = 16; valid_value <= 30; ++valid_value)
					{
						if (board[x_val][y_val][z_val].number != valid_value)
						{
							legality.push_back(0);
						}
						else{
							legality.push_back(1);
						}
					}

					for (int i = 0; i <= legality.size(); ++i){
						if (legality[i] == 1){
							legal = true;
						}
					}
					
					if (legal != true){
						return false;
					}
				}

				if (z_val == 2 || z_val == 7 || z_val == 12 || z_val == 17 || z_val == 22)
				{

				if (CentreSquare(x_val, y_val, z_val) == false){
					vector<int> legality {};
					bool legal = false;

						for(int valid_value = 31; valid_value <= 45; ++valid_value)
						{
							if (board[x_val][y_val][z_val].number != valid_value)
							{
								legality.push_back(0);
							}
							else{
								legality.push_back(1);
							}
						}

						for (int i = 0; i <= legality.size(); ++i){
							if (legality[i] == 1){
								legal = true;
							}
						}
						
						if (legal != true){
							return false;
						}
					}
				}

				if (z_val == 3 || z_val == 8 || z_val == 13 || z_val == 18 || z_val == 23)
				{

				vector<int> legality {};
				bool legal = false;

					for(int valid_value = 46; valid_value <= 60; ++valid_value)
					{
						if (board[x_val][y_val][z_val].number != valid_value)
						{
							legality.push_back(0);
						}
						else{
							legality.push_back(1);
						}
					}

					for (int i = 0; i <= legality.size(); ++i){
						if (legality[i] == 1){
							legal = true;
						}
					}
					
					if (legal != true){
						return false;
					}
				}

				if (z_val == 4 || z_val == 9 || z_val == 14 || z_val == 19 || z_val == 24)
				{

				vector<int> legality {};
				bool legal = false;

					for(int valid_value = 61; valid_value <= 75; ++valid_value)
					{
						if (board[x_val][y_val][z_val].number != valid_value)
						{
							legality.push_back(0);
						}
						else{
							legality.push_back(1);
						}
					}

					for (int i = 0; i <= legality.size(); ++i){
						if (legality[i] == 1){
							legal = true;
						}
					}
					
					if (legal != true){
						return false;
					}
				}
			}
		}
	}
	return true;
}

void CallNumber(ThreeDBingoBoard& board, int callednumber)
{
	for(int x_val = 0; x_val < 5; ++x_val)
	{
		for(int y_val = 0; y_val < 5; ++y_val)
		{
			for(int z_val = 0; z_val < 5; ++z_val)
			{
				if(board[x_val][y_val][z_val].number == callednumber)
				{
					board[x_val][y_val][z_val].covered = true;
				}
			}
		}
	}
}

///////////////////////////// Teacher's Code ////////////////////////////////////

void AllocateBoard(vector<vector<vector<ThreeDBingoSquare>>>& board)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		vector<vector<ThreeDBingoSquare>> twoDBoard;
		for (int j = 0; j < BOARD_DIM; j++)
		{
			vector<ThreeDBingoSquare> BoardRow;	
			for (int k = 0; k < BOARD_DIM; k++)
			{
				ThreeDBingoSquare tempsquare;	
				tempsquare.number = -1;
				tempsquare.covered = false;
				BoardRow.push_back(tempsquare);
			}
			twoDBoard.push_back(BoardRow);
		}
		board.push_back(twoDBoard);
	}
}

void PrintBoard(const ThreeDBingoBoard board)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				if (board[i][j][k].covered)
				{
					cout << "X" << " ";
				}
				else
				{
					cout << board[i][j][k].number << " ";
				}
			}
			cout << endl;
		}	
		if (i != BOARD_DIM-1)
		{
			cout << endl;
		}
	}		
}

void ReadBoard(ThreeDBingoBoard& board)
{
	AllocateBoard(board);
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				int temp;
				// cout << "Number: ";
				cin >> temp;	
				board[i][j][k].number = temp;
				if (CentreSquare(i, j, k))
				{
					board[i][j][k].covered = true;
				}
				else
				{
					board[i][j][k].covered = false;	
				}	
			}
		}
	}
}


bool IsWinningBoard(const ThreeDBingoBoard board)
{
	// Check rows on each Bingo board
	bool coveredrow;
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			coveredrow = true;
			for (int k = 0; k < BOARD_DIM; k++)
			{
				if (!board[i][j][k].covered)	
				{
					coveredrow = false;
				}
			}
			if (coveredrow)
			{
				return true;
			}
		}
	}

	// Check columns on each level of the ThreeD board
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int k = 0; k < BOARD_DIM; k++)
		{
			bool coveredhcol = true;
			for (int j = 0; j < BOARD_DIM; j++) 
			{
				if (!board[i][j][k].covered)
				{
					coveredhcol = false;
				}	
			}
			if (coveredhcol)
			{
				return true;
			}
		}
	}


	// Check diagonals and antidiagonals on each level of the 3D board
        for (int i = 0; i < BOARD_DIM; i++)
        {
                bool covereddiag = true, coveredantidiag = true;
                for (int j = 0; j < BOARD_DIM; j++)
                {
                        if (!board[i][j][j].covered)
                        {
                                covereddiag = false;
                        }
                        if (!board[i][j][4-j].covered) 
                        {
                                coveredantidiag = false;
                        }       
                }               
                if (covereddiag || coveredantidiag) return true;
        }       

	// Check columns along height dimension
	for (int j = 0; j < BOARD_DIM; j++)
	{
		for (int k = 0; k < BOARD_DIM; k++)
		{
			bool coveredvcol = true;
			for (int i = 0; i < BOARD_DIM; i++)	
			{
				if (!board[i][j][k].covered)
				{
					coveredvcol = false;
					break;
				}
			}
			if (coveredvcol)
			{
				return true;
			}
		}
	}

	// Check main diagonal and antidiagonal of ThreeDBingoBoard
	bool covereddiag1 = true;
	bool covereddiag2 = true;
	bool covereddiag3 = true;
	bool covereddiag4 = true;
	for (int i = 0 ; i < BOARD_DIM; i++)
	{
		if (!board[i][i][i].covered)
		{
			covereddiag1 = false;
		}
		if (!board[i][i][4-i].covered)
		{
			covereddiag2 = false;	
		}	
		if (!board[i][4-i][i].covered)
		{
			covereddiag3 = false;	
		}	
		if (!board[i][4-i][4-i].covered)
		{
			covereddiag4 = false;	
		}
	}
	if (covereddiag1 || covereddiag2 || covereddiag3 || covereddiag4) return true;

	return false;
}


////////////////////////////////////////////////// PRIMARY FUNCTION //////////////////////////////////////////////////

int main()
{
	srand(static_cast <unsigned int> (time(0)));
	
    ThreeDBingoBoard threeDBoard;
	
    try{
		ReadBoard(threeDBoard);
 		if (!BoardNumbersValid(threeDBoard))
		{
			// PrintBoard(threeDBoard);
			throw runtime_error("Invalid board input!");
		} 
	}

	catch (exception e){
		cout << "Exiting program - Exception: " << e.what() << endl;
		exit(1);
	}

	while (!IsWinningBoard(threeDBoard)){
		PrintBoard(threeDBoard);
		short callednumber;	
		cin >> callednumber;
		cout << callednumber << endl;
		CallNumber(threeDBoard, callednumber);
	} 
    
	PrintBoard(threeDBoard); 
	cout << "3D BINGO!" << endl;
}