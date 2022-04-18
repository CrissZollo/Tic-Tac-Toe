#include <iostream>
#include <string>
#include <windows.h>

void placeSymbol(int currentPlayer, char* placement, char* playerSymbols);
bool checkIfWon(int currentPlayer, int* winningPos, char* playerSymbol, char* placement, int turn);
void drawBoard(char* placement);


int main()
{
	char playerSymbols[2] = { 'X', 'O' };
	bool gameEnded = false;
	int currentPlayer = 0;
	char placement[9] = { '1' , '2' , '3' , '4' , '5' , '6' , '7', '8', '9' };
	int winningPos[8][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{1,4,7},
		{2,5,8},
		{3,6,9},
		{1,5,9},
		{3,5,7}
	};
	int currentTurn = 1;
	drawBoard(placement); // Initial Draw of the board

	while (gameEnded == false)
	{
		placeSymbol(currentPlayer, placement, playerSymbols);
		drawBoard(placement);
		gameEnded = checkIfWon(currentPlayer, (int*)winningPos, playerSymbols, placement, currentTurn);
		currentTurn++;
		currentPlayer == 0 ? currentPlayer = 1 : currentPlayer = 0;
	}

	Sleep(2000);
}

/// <summary>
/// Lets the player place a symbol on the board
/// </summary>
/// <param name="currentPlayer">The current players turn</param>
/// <param name="placement">Shows the empty/taken tiles in the game</param>
/// <param name="playerSymbols">Symbols that can be placed in the game</param>
void placeSymbol(int currentPlayer, char* placement, char* playerSymbols) {
	
	std::cout << "Player " << currentPlayer+1 << " choose a box to play in: ";
	
	int box;
	std::cin >> box;

	if (placement[box - 1] != playerSymbols[0] && placement[box - 1] != playerSymbols[1])
	{
		placement[box - 1] = playerSymbols[currentPlayer];
		system("cls");
	}
	else
	{
		std::cout << "The space was already taken, Try Again!" << std::endl;
		placeSymbol(currentPlayer, placement, playerSymbols);
	}
}

/// <summary>
/// Checks if a player has won or not
/// </summary>
bool checkIfWon(int currentPlayer, int* winningPos, char* playerSymbol, char* placement, int turn) {

	if (turn == 9) {
		std::cout << "It's a tie!";
		return true;
	}

	for (int i = 0; i < 8; i++)
	{
		int index = i * 3;
		if (placement[winningPos[index]-1] == playerSymbol[currentPlayer] && placement[winningPos[index+1]-1] == playerSymbol[currentPlayer] && placement[winningPos[index+2]-1] == playerSymbol[currentPlayer]) {
			std::cout << "Player " << currentPlayer + 1 << " wins!" << std::endl;
			return true;
		}
	}
	return false;
}

/// <summary>
/// Draws the Tic Tac Toe board with referens to the the Char array 'placement'
/// </summary>
/// <param name="placement">Shows the empty/taken tiles in the game</param>
void drawBoard(char* placement) {
	std::cout << "       |       |       " << std::endl;
	std::cout << "   "<< placement[0] << "   |   "<< placement[1] << "   |   "<< placement[2] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "   " << placement[3] << "   |   " << placement[4] << "   |   " << placement[5] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "       |       |       " << std::endl;
	std::cout << "   " << placement[6] << "   |   " << placement[7] << "   |   " << placement[8] << "   " << std::endl;
	std::cout << "       |       |       " << std::endl;
}


