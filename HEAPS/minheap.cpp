#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

template <typename k, typename v>
struct HeapItem
{
	k key;
	v value;
};

template <typename k, typename v>
class MinHeap
{
	HeapItem<k,v>* arr;
	int totalElements;
	int capacity;

	void doubleCapacity()
	{
		HeapItem<k, v>* newArr = new HeapItem<k,v>[this->capacity * 2];
		this->capacity *= 2;
		for (int i = 0; i < this->totalElements; i++)
		{
			newArr[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = newArr;
	}

public:
	MinHeap()
	{
		this->arr = new HeapItem<k,v>[1];
		this->totalElements = 0;
		this->capacity = 1;
	}

	MinHeap(int _capacity)
	{
		assert(_capacity > 0);
		this->capacity = _capacity;
		this->arr = new HeapItem<k, v>[_capacity];
		this->totalElements = 0;

	}

	void insert(k key, v value)
	{
		if (this->totalElements == this->capacity)
			this->doubleCapacity();

		arr[this->totalElements].key = key;
		arr[this->totalElements].value = value;


		shiftUp(this->totalElements);
		this->totalElements++;
	}

	void shiftUp(int index)
	{
		int parent = (index - 1) / 2;

		if (this->arr[index].key > this->arr[parent].key)
			swap(this->arr[index], this->arr[parent]);
		else return;

		if (parent>0)
		shiftUp(parent);
	}

	void deleteMin(k &key, v& value)
	{
		if (this->totalElements == 0)
			return;

		key = this->arr[0].key;
		value = this->arr[0].value;

		swap(this->arr[totalElements - 1], this->arr[0]);

		this->totalElements--;
		shiftDown(0);
	}

	void shiftDown(int i)
	{
		int lChild = i * 2+1;
		int rChild = i * 2 + 2;
		int min=i;

		if (lChild < this->totalElements && this->arr[lChild].key < this->arr[min].key)
			min = lChild;
		if (rChild < this->totalElements && this->arr[rChild].key < this->arr[min].key)
			min = rChild;

		if (min == i)
			return;

		swap(this->arr[min], this->arr[i]);
		shiftDown(min);	
	}

	int getElementCount() const
	{
		return this->totalElements;
	}

	int getCapacity() const
	{
		return this->capacity;
	}

	void print()
	{
		for (int i = 0; i < totalElements; i++)
		{
			cout << arr[i].key << " ";
		}
	}

		~MinHeap()
		{
			delete[] this->arr;
		}
};

int main()
{
	MinHeap<int,int> h(5);
	h.insert(5,2);
	h.insert(2,1);
	h.insert(3,3);
	h.insert(6,4);
	h.print();

	return 0;
}