#define CAPACITY 10
#include <iostream>

class QueueFull : std::exception
{

};

class QueueEmpty : std::exception
{

};

template <typename T>
class FixSizeQueue
{
	T arr[CAPACITY];
	int totalElements;
	int rear;
	int front;

public:
	FixSizeQueue()
	{
		this->totalElements = 0;
		this->rear = 0;
		this->front = 0;
	}
	
	bool isFull()
	{
		return this->totalElements==CAPACITY;
	}

	bool isEmpty()
	{
		return this->totalElements == 0;
	}


	void enqueue(T data)
	{
		if (isFull())
		{
			throw new QueueFull;
		}
		else
		{
			arr[rear] = data;
			totalElements++;
			rear = (rear + 1) % CAPACITY;
		}
	}

	T dequeue()
	{
		if (isEmpty())
		{
			throw new QueueEmpty();
		}
		else
		{
			T var = this->arr[front];
			front = (front + 1) % CAPACITY;
			totalElements--;
			return var;
		}
	}

	void print()
	{
		for (int i = front, j=0; j<totalElements; i=(i+1)%CAPACITY, j++)
		{
			cout << arr[i] << endl;
		}
	}
};