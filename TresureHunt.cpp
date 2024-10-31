#include "TresureHunt.hpp"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



void tresureGame(char player)
{
	TresureMap game;
	game.setPlayerCordinates(1,1);
	game.setPlayer(player);
	
	while (game.getCurrentChar() != 'X')
	{
		game.setPlayer(player);
		system("CLS");
		printf("\nwelcome to Find the tresure Game \nuse WASD to move Q to quit\n");
		printf("try to reach with %c to X \n", player);
		game.printOutter();
		game.printMap();
		game.printOutter();

		int cols = sizeof game.Map[0] / sizeof(char);
		int rows = sizeof game.Map / sizeof game.Map[0];

		while (!_kbhit());

		char input = _getch();

		switch (input)
		{
		case 'q':
		case 'Q':
			printf("\nGame Ended\n");
			return;
		case 'w':
		case 'W':
			if (game.getPlayerY() > 0)
			{
				system("CLS");
				game.setCharAtCordinates(game.getPlayerx(), game.getPlayerY(),'*');
				game.setPlayerY(game.getPlayerY()-1);
			}
			break;
		case 's':
		case 'S':
			if (game.getPlayerY() < 7)
			{
				system("CLS");
				game.setCharAtCordinates(game.getPlayerx(), game.getPlayerY(), '*');
				game.setPlayerY(game.getPlayerY() + 1);
			}
			break;
		case 'a':
		case 'A':
			if (game.getPlayerx() > 0)
			{
				system("CLS");
				game.setCharAtCordinates(game.getPlayerx(), game.getPlayerY(), '*');
				game.setPlayerX(game.getPlayerx() - 1);
			}
			break;
		case 'd':
		case 'D':
			if (game.getPlayerx() < 7)
			{
				system("CLS");
				game.setCharAtCordinates(game.getPlayerx(), game.getPlayerY(), '*');
				game.setPlayerX(game.getPlayerx() + 1);
			}
			break;
		defult:
			system("CLS");
			break;
		}
	}
	printf("\nYou Won!\n");

}

void TresureMap::setPlayer(char p)
{
	this->player = p;
	Map[this->playerY][this->playerX] = p;
}
void TresureMap::setPlayerCordinates(int x, int y)
{
	this->playerX = x;
	this->playerY = y;
}
void TresureMap::setPlayerY(int y)
{
	this->playerY = y;
}
void TresureMap::setPlayerX(int x)
{
	this->playerX = x;
}
char TresureMap::getCurrentChar()
{
	return this->Map[playerY][playerX];
}

void TresureMap::printOutter() {
	printf("+");
	int cols = sizeof Map[0] / sizeof(char);
	for (int i = 0; i < cols; i++) printf("-");
	printf("+\n");
}

void TresureMap::printMap()
{
	int cols = sizeof this->Map[0] / sizeof(char);
	int rows = sizeof this->Map / sizeof this->Map[0];
	for (int i = 0; i < rows; i++)
	{
		printf("|");
		for (int j = 0; j < cols; j++)
			printf("%c", Map[i][j]);
		printf("|");
		printf("\n");
	}
}

int TresureMap::getPlayerY()
{
	return TresureMap::playerY;
}
int TresureMap::getPlayerx()
{
	return TresureMap::playerX;
}

void TresureMap::setCharAtCordinates(int x, int y, char p)
{
	Map[y][x] = p;
}
