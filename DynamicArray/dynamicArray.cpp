#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[capacite];

	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

int DynamicArray::getCapacite()
{
	return capacite;
}

int DynamicArray::getElement(int _position)
{
	return tabElements[_position];
}
