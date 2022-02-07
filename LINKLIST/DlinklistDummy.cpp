#include <iostream>
using namespace std;

template <typename T>
struct DNode
{
	T data;
	DNode* next;
	DNode* prev;
};

template <typename T>
class DLinkList
{
private:
	DNode<T>* head;
	DNode<T>* tail;
	int totalElements;

public:
	DLinkList()
	{
		this->totalElements = 0;
		head = new DNode<T>;
		tail = new DNode<T>;
		head->next = tail;
		head->prev = nullptr;
		tail->next = nullptr;
		tail->prev = head;
	}

	void insertAtHead(T data)
	{
		DNode<T>* newNode = new DNode<T>;
		newNode->data = data;
		newNode->next = this->head->next;
		newNode->prev = this->head;
		newNode->next->prev = newNode;
		this->head->next = newNode;
	}

	void insertAtTail(T data)
	{
		DNode<T>* newNode = new DNode<T>;
		newNode->data = data;
		newNode->next = this->tail;
		newNode->prev = this->tail->prev;
		newNode->next->prev = newNode;
		newNode->prev->next = newNode;
	}

	void print()
	{
		DNode<T>* curr = this->head->next;
		while (curr != this->tail)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
	}

	void deleteFromTail()
	{
		if (!isEmpty())
		{
			DNode<T>* delNode = this->tail->prev;
			this->tail->prev = delNode->prev;
			delNode->prev->next = this->tail;
			delete delNode;
			this->totalElements--;
		}
	}
	void deleteFromHead()
	{
		if (!isEmpty())
		{
			DNode<T>* delNode = this->head->next;
			this->head->next = delNode->next;
			delNode->next->prev = this->head;
			delete delNode;
			this->totalElements--;
		}
	}
	
	bool isEmpty()
	{
		return this->head->next == this->tail;
	}

	~DLinkList()
	{	
		while (head)
		{
			DNode<T>* deleteNode = head;
			head = head->next;
			delete deleteNode;
		}
	}



};