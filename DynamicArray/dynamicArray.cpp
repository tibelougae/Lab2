#include "dynamicArray.h"

DynamicArray::DynamicArray(int _capaciteDepart)
{
	if (_capaciteDepart < 1) throw invalid_argument("L'argument est invalide, il doit être au moins 1");
	capacite = _capaciteDepart;
	initializeTab();
}

void DynamicArray::setCapacite(int _nouvelleCapacite)
{
	int * tabTemporaire = new int[_nouvelleCapacite];

	for (int i = 0; i < _nouvelleCapacite; i++)
	{
		i < capacite ? tabTemporaire[i] = tabElements[i] : tabTemporaire[i] = 0;
	}
	delete tabElements;
	capacite = _nouvelleCapacite;
	tabElements = tabTemporaire;
}

int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setElement(int _position, int _valeur)
{
	if (_position < capacite)
	{
		tabElements[_position] = _valeur;
	}
	else
	{
		setCapacite(_position);
		tabElements[_position] = _valeur;
	}
}

int DynamicArray::getElement(int _position)
{
	return tabElements[_position];
}

void DynamicArray::initializeTab()
{
	tabElements = new int[capacite];

	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}
