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
void PowerWithPointers(int*a, int b, int res = 1);
int PowerWithOutPointers(int a, int b);

void sortingMenu();
void employeeMenu();

void insertSort(std::vector<int>* arr);
void bubbleSort(std::vector<int>* arr);

int main()
{
	mainMenu();
}

void mainMenu() 
{
	printf(" 1- find the ASCII code of string\n 2- find the sum and average of array");
	printf("\n 3- find the tallset and shortest sentence \n 4-find the tresure game \n 5- game elemwnt structs size \n 6- factorial");
	printf("\n 7- time taple\n 8- Open Inventory \n 9- power ");
	printf("\n 10- sorting Menu");
	printf("\n 11- Employee Menu");
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
	case 10:
		sortingMenu();
		break;
	case 11:
		employeeMenu();
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
	printf("\npress Enter to Retrun to Previous Menu...");
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
	if (n < 2) return n;
	return n * factorialWithOutPointers(n-1);
}
void PowerWithPointers(int* a, int b,int res)
{
	
	if (b < 1)
	{
		*a = res;
		return;
	}
	res *= *a;
	b--;
	PowerWithPointers(a, b, res);
}
int PowerWithOutPointers(int a, int b)
{
	if (b < 1) return 1;
	return a * PowerWithOutPointers(a, b - 1);
}

void sortingMenu()
{

	std::vector<int> arr;
	bool flag = true;
	while (flag)
	{
		system("CLS");
		printf("1- Enter array Elemnts\n");
		printf("2- bubble sort\n");
		printf("3- insertation sort\n");
		printf("4- return to Main Menu\n");



		int x;
		scanf("%d", &x);

		switch (x)
		{
		case 1:
			printf("how many elemnts you wanna add: \n");
			int y;
			scanf("%d", &y);
			printf("enter intgers \n");
			for (int i = 0; i < y; i++)
			{
				int b;
				scanf("%d", &b);
				arr.push_back(b);
			}

			break;
		case 2:
			printf("before bubble sort:\n");
			for (int i : arr)
				printf("%d, ", i);

			printf("\n");
			printf("After bubble sort:\n");
			bubbleSort(&arr);

			for (int i : arr)
				printf("%d, ", i);
			returnToMainMenu();
			break;
		case 3:
			printf("\nbefore insertation sort:\n");
			for (int i : arr)
				printf("%d, ", i);
			printf("\n after insertation sort:\n");
			insertSort(&arr);

			for (int i : arr)
				printf("%d, ", i);
			returnToMainMenu();
			break;
		case 4:
			
			flag = false;
			break;

		default:
			break;
		}
	}
	returnToMainMenu();
	mainMenu();
}
void employeeMenu()
{

}

void bubbleSort(std::vector<int>* arr)
{
	int size = arr->size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if ((*arr)[i] < (*arr)[j])
			{
				int temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
		}
	}
}
void insertSort(std::vector<int>* arr)
{
	int size = arr->size();
	for (int i = 0; i < size; i++)
	{
		int key = (*arr)[i];
		int j = i - 1;
		while (j >= 0 && (*arr)[j] > key)
		{
			(*arr)[j + 1] = (*arr)[j];
			j--;
		}
		(*arr)[j + 1] = key;
		//for (int j = i - 1; j > -1; j--)
		//{
		//	if (key > (*arr)[j])
		//	{
		//		arr->insert(arr->begin() + j, key);
		//		arr->erase(arr->begin() + i+1);

		//		/*printf("%d - %d: ", i, j);
		//		for (int A : *arr)
		//		{
		//			printf("%d, ", A);

		//		}
		//		printf("\n");*/

		//		i = j-1;
		//		break;
		//	}
		//}

	}


}