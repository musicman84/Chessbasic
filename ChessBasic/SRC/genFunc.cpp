#include "genFunc.h"
char numToLet(int original)//convert ints to numbers for output only
{
	char const numToLet[] = "ABCDEFGH";
	if (original >= 0 && original < sizeof(numToLet) - 1)
	{
		return numToLet[original];
	}
	else return '0';
	//else exit(69);
}