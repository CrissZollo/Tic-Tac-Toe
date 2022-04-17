#include <iostream>
#include <string>

void placeSymbol(int player);
void drawBoard(char* placement);


int main()
{
	char placement[9] = { '1' , '2' , '3' , '4' , '5' , '6' , '7', '8', '9' };
	drawBoard(placement);
}

void placeSymbol(int player) {
	char symbol;
	std::cin >> symbol;
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


