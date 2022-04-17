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
	drawBoard(placement);

	while (gameEnded == false)
	{
		placeSymbol(currentPlayer, placement, playerSymbols);
		drawBoard(placement);

		currentPlayer == 0 ? currentPlayer = 1 : currentPlayer = 0;
	}
}

void placeSymbol(int currentPlayer, char* placement, char* playerSymbols) {
	
	std::cout << "Player " << currentPlayer+1 << " choose a box to play in: ";
	
	int box;
	std::cin >> box;

	placement[box - 1] = playerSymbols[currentPlayer];
	system("cls");
}


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


