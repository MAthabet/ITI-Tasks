#pragma once
struct Position
{
	float x;
	float y;
	float z;
};
struct Rotation
{
	float x;
	float y;
	float z;
};
struct Player 
{
	Position posVector;
	Rotation rotVector;
	char name[32];
	double mass;
};
struct Enemy
{
	int meshID;
	char name[32];
	double speed;
};


