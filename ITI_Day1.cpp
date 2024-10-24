
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "struct.h"
#include <vector>

struct Item
{
	int itemID;
	int ItemCount;
	Item(int x, int y)
	{
		itemID = x;
		ItemCount = y;
	}
};

struct Inventory
{
	int playerID;
	std::vector<Item> items;
	Inventory(int x)
	{
		playerID = x;
	}
	void addItem(int id, int count)
	{
		for (auto& item : items)
		{
			if (item.itemID == id)
			{
				item.ItemCount += count;
				return;
			}
		}
		items.push_back(Item(id, count));
	}
	int getItemCount(int id)
	{
		for (auto& item : items)
		{
			if (item.itemID == id)
			{
				return item.ItemCount;
			}
		}
		return 0;
	}
};

void mainMenu();
void sumAndAvg();
void tallestAndShortest();
void tresureGame(char player);
void returnToMainMenu();
void printOutter();
void findSizeOfStruct();
void printTimeTapleOfNumber(int n, int i = 0);
void invHandler();

int factorialWithPointers(int* n);
int factorialWithOutPointers(int n);
void PowerWithPointers(int* a, int b);
int PowerWithOutPointers(int a, int b);



int main()
{
	mainMenu();
}
void mainMenu() 
{
	printf(" 1- find the ASCII code of string\n 2- find the sum and average of array");
	printf("\n 3- find the tallset and shortest sentence \n 4-find the tresure game \n 5- game elemwnt structs size \n 6- factorial");
	printf("\n 7- time taple\n 8- Open Inventory \n 9- power \n ");
	int x;
	printf("\nEnter Your choice: ");
	scanf("%d", &x);

	system("CLS");
	switch (x) {
	case 1:
	{
		char str[50];
		printf("\n Enter Your String:");
		scanf("%s", &str);
		int i = 0;
		printf("\n Your String in ASCII: ");
		while (str[i] != '\0')
		{
			printf("%d ", str[i]);
			i++;
		}
	}
		break;
	case 2:
		sumAndAvg();
		break;
	case 3:
		tallestAndShortest();
		break;
	case 4:
		printf("\n Pick a Character to play with:");
		char player;
		scanf("%c", &player);
		scanf("%c", &player);
		tresureGame(player);
		break;
	case 5:
		findSizeOfStruct();
		break;
	case 6:
		printf("\nenter a number");
		int n;
		scanf("%d", &n);
		printf("%d",factorialWithPointers(&n));
		break;
	case 7:
	{
		printf("Enter number: \n");
		int n;
		scanf("%d", &n);
		printTimeTapleOfNumber(n);
		break;
	}
	case 8:
		invHandler();
		break;
	case 9:
		printf("Enter base: \n");
		int a;
		scanf("%d", &a);
		printf("Enter power: \n");
		int b;
		scanf("%d", &b);
		PowerWithPointers(&a, b);
		printf("%d", a);
		break;
	default:
		printf("\a please enter correct number");
		printf("\n----------------------------------------------------------------\n");
		break;
	}

	returnToMainMenu();
	mainMenu();
	return;
}

void sumAndAvg()
{
	int arr[5];
	int sum = 0;
	printf("enter 5 numbers: \n");
	for (int i = 0; i < 5; i++)
	{
		printf("number %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		sum += arr[i];
	}
	int avg = sum / 5;
	printf("\n sum = %d \n avg = %d", sum, avg);
}

void tallestAndShortest()
{
	char str[5][50];
	int strLenArr[5];
	printf("\nenter 5 sentances: \n");
	for (int i = 0; i < 5; i++) {
		printf("sentance %d:", i + 1);
		scanf("%s", &str[i]);
		int strLen = 0;
		while (str[i][strLen] != '\0') {
			strLen++;
		}
		strLenArr[i] = strLen;
	}
	int max = 0;
	int min = 50;
	int longestStrInd = 0;
	int shortestStrInd = 0;
	for (int i = 0; i < 5; i++) {
		if (strLenArr[i] > max) {
			longestStrInd = i;
			max = strLenArr[i];
		}
		else if (strLenArr[i] < min) { shortestStrInd = i;min = strLenArr[i]; }
	}
	printf("\n Longest str: %s", str[longestStrInd]);
	printf("\n shortest str: %s", str[shortestStrInd]);
}

void tresureGame(char player)
{
	char boundryArr[8][8] = 
	{
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','X','*','*'}
	};
	int playerX = 1;
	int playerY = 0;
	boundryArr[playerY][playerX] = player;

	//int boundryArrSize = sizeof(boundryArr) / sizeof(boundryArr[0]);

	while (boundryArr[playerY][playerX] != 'X')
	{
		boundryArr[playerY][playerX] = player;
		system("CLS");
		printf("\nwelcome to Find the tresure Game \nuse WASD to move Q to quit\n");
		printf("try to reach with %c to X \n", player);
		printOutter();
		for (int i = 0; i < 8; i++)
		{
			printf("|");
			for (int j = 0; j < 8; j++) 
				printf("%c", boundryArr[i][j]);
			printf("|");
			printf("\n");
		}
		printOutter();

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
				if (playerY > 0)
				{
					system("CLS");
					boundryArr[playerY][playerX] = '*';
					playerY--;
				}
				break;
			case 's':
			case 'S':
				if (playerY < 7)
				{
					system("CLS");
					boundryArr[playerY][playerX] = '*';
					playerY++;
				}
				break;
			case 'a':
			case 'A':
				if (playerX > 0)
				{
					system("CLS");
					boundryArr[playerY][playerX] = '*';
					playerX--;
				}
				break;
			case 'd':
			case 'D':
				if (playerX < 7)
				{
					system("CLS");
					boundryArr[playerY][playerX] = '*';
					playerX++;
				}
				break;
			defult:
				system("CLS");
				break;
			}
	}
	printf("\nYou Won!\n");
	
}

void returnToMainMenu() {
	printf("\npress Enter to Retrun to Main Menu...");
	while (_getch() != '\r');
	system("CLS");
}

void printOutter() {
	printf("+");
	for (int i = 0; i < 8; i++) printf("-");
	printf("+\n");
}

void findSizeOfStruct() 
{
	printf("Size of position struct is: %d\n", sizeof(Position));
	printf("Size of Rotation struct is: %d\n", sizeof(Rotation));
	printf("Size of Player struct is: %d\n", sizeof(Player));
	printf("Size of Enemy struct is: %d\n", sizeof(Enemy));
}

void printTimeTapleOfNumber(int n, int i)
{
	if (i == 11) return;
	printf("%d * %d = %d\n", n, i, n * i);
	printTimeTapleOfNumber(n, i + 1);	
}
void invHandler()
{
	int id, choice, itemId, count;
	printf("enter inventory ID to create:\n");
	scanf("%d", &id);
	Inventory inventory(id);
	while (bool f = true)
	{
		printf("You are in inventory %d\n", inventory.playerID);
		printf("---------------------------------------------\n");
		printf("1- add by Item ID to current inventory\n");
		printf("2- see how many item in the current inventory\n");
		printf("3- Disply the whole inventory\n");
		printf("4-exit\n");
		printf("enter your option:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter Item ID to add");
			scanf("%d", &itemId);
			printf("How many Item to add");
			scanf("%d", &count);
			inventory.addItem(itemId, count);
			break;
		case 2:
			printf("Enter Item ID to look for");
			scanf("%d", &itemId);
			printf("there is %d form item%d in thie inventory", inventory.getItemCount(itemId), itemId);
		case 3:
			printf("Inventory Items:\n");
			for (const auto& item : inventory.items) {
				printf(" itemID : %d | count : %d\n", item.itemID, item.ItemCount);
			}
		case 4:
			f = false;
			break;
		}
		returnToMainMenu();
	}
}


int factorialWithPointers (int* n)
{
	if (*n < 2) return 1;
	int num = *n - 1;
	return *n * factorialWithPointers(&num);
}
int factorialWithOutPointers(int n)
{
	int result = 1;
	while (n > 0)
	{
		result *= n;
		n--;
	}
	return result;
}
void PowerWithPointers(int *a, int b)
{
	int res = *a;
	for (int i = 1; i < b; i++)
	{
		res *= *a;
	}
	*a = res;
}
int PowerWithOutPointers(int a, int b)
{
	int result = 1;
	while (b > 0) {
		result *= a;
		b--;
	}
	return result;
}