#define _CRT_SECURE_NO_WARNINGS

#include "ComplexNumbers.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "struct.h"
#include <vector>
#include <string>
#include <iostream>


#pragma region structs
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

struct Node
{
	int ID;
	std::string Name;
	Node* next = NULL;
	Node* prev = NULL;
	void printNode()
	{
		std::cout << "Name: " << Name << "\n";
		std::cout << "ID: " << ID << "\n";
	}
	Node(std::string name, int id)
	{
		Name = name;
		ID = id;
	}
};
struct LinkedList
{
	Node* Head = NULL;
	Node* tail = NULL;
	int Size()
	{
		Node* current = Head;
		int size = 0;
		while (current != NULL)
		{
			size++;
			current = current->next;
		}
		return size;
	}
	void addEmp(Node* emp)
	{
		if (Head == NULL)
		{
			Head = emp;
			tail = emp;
			emp->next = NULL;
			emp->prev = NULL;
			return;
		}
		tail->next = emp;
		emp->prev = tail;
		emp->next = NULL;
		tail = emp;
	}
	void push(Node node)
	{
		Node* NewNode = new Node(node.Name, node.ID);
		if (Head == NULL)
		{
			Head = NewNode;
			tail = NewNode;
			NewNode->next = NULL;
			NewNode->prev = NULL;
			return;
		}
		tail->next = NewNode;
		NewNode->prev = tail;
		NewNode->next = NULL;
		tail = NewNode;
	}
	Node* getNode(int index)
	{
		if (index > Size()) return NULL;

		Node* current = Head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		
		return current;
	}
	Node* findEmp(int id)
	{
		Node* current = Head;


		while (current != NULL)
		{
			if (current->ID == id) return current;
			current = current->next;
		}
		return NULL;
	}

	void deleteEmpByID(int id)
	{
		Node* emp = findEmp(id);
		if (emp == Head)
		{
			Head = emp->next;
			Head->prev = NULL;
		}
		if (emp == tail)
		{
			tail = emp->prev;
			tail->next = NULL;
		}
		if (emp->prev != NULL)
			(emp->prev)->next = emp->next;
		if (emp->next != NULL)
			(emp->next)->prev = emp->prev;
	}
	void swap(int i, int j)
	{
		Node* Old = getNode(i);
		Node* New = getNode(j);

		if (Old == Head) Head = New;
		else if (Head == New) Head = Old;
		if (Old == tail) tail = New;
		else if (tail == New) tail = Old;
		Node* temp = New->next;
		New->next = Old->next;
		Old->next = temp;
		temp = New->prev;
		New->prev = Old->prev;
		Old->prev = temp;
	}
	void replaceEmp(Node* Old, Node* New)
	{
		if (Old == Head) Head = New;
		if (Old == tail) tail = New;
		New->next = Old->next;
		New->prev = Old->prev;
		if (Old->prev != NULL)
			(Old->prev)->next = New;
		if (New->next != NULL)
			(New->next)->prev = New;
	}
	void printAll()
	{
		Node* current = Head;

		while (current != NULL)
		{
			current->printNode();
			current = current->next;
		}
	}
};
LinkedList Employees;
struct Qeueu
{
	Node* first = NULL;
	Node* last = NULL;

	void enqueue(Node* n)
	{
		if (first == NULL)
		{
			first = n;
			first->next = NULL;
		}
		else
		{
			last->prev = n;
			n->next = last;
		}
		last = n;
	}
	Node* dequeue()
	{
		Node* temp = first;
		first = first->prev;
		first->next = NULL;
		return temp;
	}
	Node* findNode(int id)
	{
		Node* n = first;
		while (n != NULL)
		{
			if (n->ID == id) break;
			n = n->prev;
		}
		return n;
	}
	void enqeueuAtIndex(Node* node, int I)
	{
		Node* n = first;

		if (I == 0) first = node;


		while (I > 0)
		{
			n = n->prev;
			I--;
		}
		if (n->next != NULL) n->next->prev = node;
		node->next = n->next;
		node->prev = n;
		n->next = node;



		first->next = NULL;
	}
	void printQ()
	{
		Node* n = first;
		while (n != NULL)
		{
			n->printNode();
			n = n->prev;
		}
	}

};

struct BTNode
{
	int ID;
	std::string name;
	BTNode* R = NULL;
	BTNode* L = NULL;
	BTNode* parent = NULL;
	BTNode(int id, std::string s)
	{
		name = s;
		ID = id;
	}
	void printBTNode()
	{
		std::cout << "\nStudent Name : " << name;
		std::cout << " Student ID : " << ID;
	}
};

struct BinaryTree
{
	BTNode* head = NULL;

	void insert(BTNode* n)
	{
		BTNode* current = head;
		BTNode* parent = NULL;

		if (current == NULL)
		{
			head = n;
			n->parent = parent;
			return;
		}
		while (current != NULL)
		{
			parent = current;
			if (n->ID > current->ID) current = current->R;
			else current = current->L;
		}
		current = n;
		if (current->ID > parent->ID) parent->R = n;
		else parent->L = n;
		n->parent = parent;
	}
	BTNode* find(int id)
	{
		BTNode* current = head;
		while (current != NULL && current->ID != id)
		{

			if (current->ID < id) current = current->R;
			else current = current->L;
		}
		return current;
	}
	int remove(BTNode* student)
	{
		// node not found
		if (find(student->ID) == NULL) return -1;

		// node has no children
		if (student->L == NULL && student->R == NULL)
		{
			if (student == head)
			{
				head = NULL;
			}
			else
			{
				if (student->parent->L == student)
				{
					student->parent->L = NULL;
				}
				else
				{
					student->parent->R = NULL;
				}
			}
			return 0;
		}

		// node has only one child
		if (student->L == NULL || student->R == NULL)
		{
			BTNode* child;
			if (student->L == NULL) child = student->R;

			else child = student->L;

			if (student == head) head = child;

			else
			{
				if (student->parent->L == student) student->parent->L = child;
				else student->parent->R = child;
			}
			child->parent = student->parent;

			return 0;
		}
		
		//node has 2 child
		BTNode* minNode = student->R;
		if (head == student)
		{
			head = minNode;
		}
		else if (student->parent->L == student)
		{
			student->parent->L = minNode;
		}
		else
		{
			student->parent->R = minNode;
		}
		while (minNode->L != NULL)
		{
			minNode = minNode->L;
		}
		minNode->L = student->L;
		head->parent = NULL;

		return 0;
	}

	void printTree(BTNode* node) {

		if (node == NULL) return;

		printTree(node->L);
		node->printBTNode();
		printTree(node->R);
	}
};
#pragma endregion

#pragma region Funch_dec
void mainMenu();
void sumAndAvg();
void tallestAndShortest();
void tresureGame(char player);
void returnToMainMenu();
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

LinkedList mergeSort(LinkedList* LL);

void qeueuMenu();
void bstMenu();

void compNUmMenu();
#pragma endregion  

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
	printf("\n 12- Qeueu Menu");
	printf("\n 13- Binary Tree Menu");
	printf("\n 14- Complex Numbers");
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
	case 12:
		qeueuMenu();
		break;
	case 13:
		bstMenu();
		break;
	case 14:
		compNUmMenu();
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


#pragma region day1_tasks

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

void returnToMainMenu() {
	printf("\npress Enter to Retrun to Previous Menu...");
	while (_getch() != '\r');
	system("CLS");
}

#pragma endregion

#pragma region struct_tasks
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
#pragma endregion

#pragma region day3_tasks
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
	Node emp0 = Node("bla", 7);
	Node emp1 = Node("Mohamed", 5);
	Node emp2 = Node("Alaa", 6);
	Node emp3 = Node("Ahmed", 0);
	Employees.addEmp(&emp0);

	Employees.addEmp(&emp1);

	Employees.addEmp(&emp2);

	Employees.addEmp(&emp3);
	Employees.printAll();

	Employees = mergeSort(&Employees);
	std::cout << "\nName of employees after sort \n";
	Employees.printAll();
	std::cout << "\nName of employee with ID ";

	int x;

	std::cin >> x;
	if (Employees.findEmp(x) != NULL)
		std::cout << (Employees.findEmp(x))->Name;
	else
		std::cout << "there is no employee with id \n" << x;

	Node emp4 = Node("blabla", 13);
	Employees.replaceEmp(&emp0, &emp4);
	std::cout << "\n\nName of employees after replacment\n";
	Employees.printAll();
	Employees.deleteEmpByID(13);
	std::cout << "\nName of employees after deletion\n";
	Employees.printAll();
	returnToMainMenu();
	bool flag = true;
	//LinkedList Employees;
	while (flag)
	{
		system("CLS");
		printf("1- Add Employee\n");
		printf("2- Delete Employee By ID\n");
		printf("3- Find an Employee\n");
		printf("4- Replace employees\n");
		printf("5- print All Employees\n");
		printf("6- sort Employees\n");
		printf("7- exit\n");
		int x;
		scanf("%d", &x);
		system("CLS");
		switch (x)
		{
		case 1:
		{
			printf("insert employee's ID\n");
			int id;
			std::cin >> id;
			printf("insert employee's name\n");
			std::string temp;
			std::cin >> temp;
			Node emp0 = Node(temp, id);
			Employees.addEmp(&emp0);
			std::cout << "Employee with ID: "<<emp0.ID<<" And name : " << emp0.Name;
			std::cout << " is added\n";
			
			returnToMainMenu();
			break;
		}
		case 2:
			printf("insert employee's ID\n");
			int idToDel;
			std::cin >> idToDel;
			Employees.deleteEmpByID(idToDel);
			break;
		case 3:
			printf("insert employee's ID\n");
			int idToFind;
			std::cin >> idToFind;
			std::cout << "Employees with ID : " << idToFind;
			std::cout << " is Named : " << (Employees.findEmp(idToFind))->Name;
			returnToMainMenu();
			break;
		case 4:
			printf("insert new employee's ID to add\n");
			int newID;
			std::cin >> newID;
			printf("insert old employee's ID to be rplaced\n");
			int oldID;
			std::cin >> oldID;
			Employees.replaceEmp(Employees.findEmp(oldID), Employees.findEmp(newID));
			break;
		case 5:
			Employees.printAll();
			returnToMainMenu();
			break;
		case 6:
			//TODO:sort List
		case 7:
			flag = false;
			break;
		default:
			break;
		}
	}

	returnToMainMenu();
	mainMenu();

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

LinkedList mergeSort(LinkedList* LL)
{
	int size = LL->Size();
	
	if (size == 1) return *LL;
	if (size == 2)
	{
		Node* temp = LL->getNode(0);
		Node* temp1 = LL->getNode(1);
		if (temp->ID < temp1->ID)
		{
			//swap but it is just 2 elemnts array :D
			LL->Head = temp1;
			temp1->next = temp;
			temp1->prev = NULL;
			LL->tail = temp;
			temp->prev = temp1;
			temp->next = NULL;
		}
		return *LL;
	}
	
	int last = size - 1;
	int first = 0;
	int mid = (first + last) / 2;
	LinkedList ll1, ll2;
	for (int i = first; i <= mid; i++)
	{
		Node node = *(LL->getNode(i));
		ll1.push(node);
	}
	for (int i = mid+1; i <= last; i++)
	{
		Node node = *(LL->getNode(i));
		ll2.push(node);
	}

	ll1 = mergeSort(&ll1);
	ll2 = mergeSort(&ll2);

	int i = 0;
	int j = 0;
	int ll1Size = ll1.Size();
	int ll2Size = ll2.Size();
	LinkedList sorted;
	while (i < ll1Size && j < ll2Size)
	{
		if (ll1.getNode(i)->ID < ll2.getNode(j)->ID)
		{
			sorted.push(*(ll2.getNode(j)));
			j++;
		}
		else
		{
			sorted.push(*(ll1.getNode(i)));
			i++;
		}
	}
	if (i >= ll1Size)
	{
		for (;j< ll2Size;j++)
			sorted.push(*(ll2.getNode(j)));
		return sorted;
	}
	if (j >= ll2Size)
	{
		for (;i < ll1Size;i++)
			sorted.push(*(ll1.getNode(i)));
		return sorted;
	}
}
#pragma endregion

#pragma region day4_tasks
void qeueuMenu()
{
	Qeueu q;
	Node a = Node ("a" ,1);
	Node b = Node ("b" ,2);
	Node c = Node ("c" ,3);

	q.enqueue(&a);
	q.enqueue(&b);
	q.enqueue(&c);
	printf("current Queue:\n");
	q.printQ();

	printf("dequeued ID: %d \n", q.dequeue()->ID);

	printf("trying to find employee with ID:2 .....");
	Node* n = q.findNode(2);
	if (n == NULL)
		std::cout << "NOT FOUND";
	else
		std::cout << n->Name << "\n";

	Node d = Node("d", 4);

	q.enqeueuAtIndex(&d, 0);
	q.printQ();
	std::cout << "\n-------\n";

	Node e = Node("e",5);

	q.enqeueuAtIndex(&e, 1);
	q.printQ();
}

void bstMenu()
{
	BTNode n5 = BTNode(5, "a");
	BTNode n1 = BTNode(1, "b");
	BTNode n9 = BTNode(9, "c");
	BTNode n10 = BTNode(10, "d");
	BTNode n8 = BTNode(8, "e");
	BinaryTree t;
	t.insert(&n5);
	t.insert(&n1);
	t.insert(&n9);
	t.insert(&n10);
	t.insert(&n8);
	BTNode* res = t.find(2);
	
	printf("Searching fot student with ID: 2 ....\n");
	if (res == NULL) std::cout << "\nStudent with ID: 2  Not Found!";
	else res->printBTNode();

	printf("Searching for student with ID: 5 ....\n");
	res = t.find(5);
	if (res == NULL) std::cout << "\nStudent with ID: 5   Not Found!";
	else res->printBTNode();

	printf("\nAll tree elemnts ....\n");
	t.printTree(t.head);
	t.remove(&n5);
	std::cout << "\nafter removing\n";
	t.printTree(t.head);
}
#pragma endregion

#pragma region day5_tasks
void compNUmMenu() 
{
	int a, b;

	printf("\nEnter first complex number (R +Ii):");
	printf("\n Enter Real part : ");
	scanf("%d", &a);
	printf("\n Enter Imaginry part : ");
	scanf("%d", &b);
	ComplexNumber x = ComplexNumber(a, b);

	printf("\nEnter Second complex number (R +Ii):");
	printf("\n Enter Real part : ");
	scanf("%d", &a);
	printf("\n Enter Imaginry part : ");
	scanf("%d", &b);

	ComplexNumber y = ComplexNumber(a, b);
	ComplexNumber ans;
	add(&x, &y,&ans);

	printf("\n");
	x.print();printf(" + ");y.print();printf(" = ");
	ans.print();
	printf("\n");

	subtract(&x, &y,&ans);
	x.print();printf(" - ");y.print();printf(" = ");
	ans.print();
	printf("\n");
	printf("complex numbers counter : %d", ComplexNumber::counter);
}

#pragma endregion