#include "dynamicArray.h"

DynamicArray::DynamicArray(int _capaciteDepart)
{
	if (_capaciteDepart < 1) throw invalid_argument("L'argument est invalide, il doit être au moins 1");
	capacite = _capaciteDepart;
	initializeTab();
}

void DynamicArray::setCapacite(int _nouvelleCapacite)
{
	if (_nouvelleCapacite < 1) { throw invalid_argument("L'argument est invalide"); };
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
	if (_position > capacite) { throw out_of_range("La position doit se trouver dans le tableau"); };
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

bool DynamicArray::operator==(DynamicArray& _other) const
{
	bool result = true;

	for (int i = 0; i < capacite && result; i++)
	{
		if (tabElements[i] != _other.tabElements[i])
		{
			result = false;
		}
	}

	if (capacite != _other.capacite)
	{
		result = false;
	}

	return result;
}

const DynamicArray& DynamicArray::operator=(DynamicArray& _other)
{
	capacite = _other.capacite;
	tabElements = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = _other.tabElements[i];
	}

	return *this;
}

const DynamicArray& DynamicArray::operator+=(DynamicArray& _other)
{
	int oldCapacity = capacite;
	capacite += _other.capacite;
	int *newArray = new int[capacite];

	for (int i = 0; i < capacite; i++)
	{
		i < oldCapacity ? newArray[i] = tabElements[i] : newArray[i] = _other.tabElements[i - oldCapacity];
	}

	tabElements = newArray;

	return *this;
}
