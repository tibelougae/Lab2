#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(int);
	void setCapacite(int);
	int getCapacite();
	void setElement(int, int);
	int getElement(int);
private:
	void initializeTab();
	int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_