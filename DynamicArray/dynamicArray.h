#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	int getCapacite();
	int getElement(int);
private:
	int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_