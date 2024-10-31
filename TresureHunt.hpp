class TresureMap
{
private:
	char player = 'U';
	int playerX = 0;
	int playerY = 0;

public:
	//X is the goal
	char Map[8][8] = 
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
	void setPlayer(char p);
	void setPlayerCordinates(int x, int y);
	void setPlayerY(int y);
	void setPlayerX(int x);
	void setCharAtCordinates(int x, int y, char p);
	char getCurrentChar();
	void printOutter();
	void printMap();
	int getPlayerY();
	int getPlayerx();



	
};

