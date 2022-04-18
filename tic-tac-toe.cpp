#include <iostream>
#include <string>

void placeSymbol(int currentPlayer, char* placement, char* playerSymbols);
void drawBoard(char* placement);


int main()
{
	char playerSymbols[2] = {'X', 'O'};
	bool gameEnded = false;
	int currentPlayer = 0;
	char placement[9] = { '1' , '2' , '3' , '4' , '5' , '6' , '7', '8', '9' };
	drawBoard(placement); // Initial Draw of the board

	while (gameEnded == false)
	{
		placeSymbol(currentPlayer, placement, playerSymbols);
		drawBoard(placement);

		currentPlayer == 0 ? currentPlayer = 1 : currentPlayer = 0;
	}
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


