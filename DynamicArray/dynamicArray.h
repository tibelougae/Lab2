#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

using namespace std;
#include <iostream>

class DynamicArray
{

public:
	DynamicArray(int capacite = 100);
	void setCapacite(int);
	int getCapacite();
	void setElement(int, int);
	int getElement(int);

	bool operator==(DynamicArray& _other) const;
	const DynamicArray& operator=(DynamicArray& _other);
	const DynamicArray& operator+=(DynamicArray& _other);

private:

	void initializeTab();
	int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_