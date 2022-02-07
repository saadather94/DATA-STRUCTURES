#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
class CircularLinkList
{
private:
	Node<T>* head;
	Node<T>* tail;

	int totalElements;
public:
	CircularLinkList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->totalElements = 0;
	}

	bool isEmpty() const
	{
		return !this->head;
	}

	void insertAtHead(T data)
	{
		if (isEmpty())
		{
			this->head = this->tail = new Node<T>();
			this->head->data = data;
			this->head->next = this->head;
			totalElements++;
		}

		else
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = this->head;
			this->head = newNode;
			this->tail->next = this->head;
			totalElements++;
		}
	}

	void insertAtTail(T data)
	{
		if (this->isEmpty()) //if list is empty.
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			this->head = this->tail = newNode;
			this->tail->next = this->head;
			totalElements++;
		}
		else
		{
			Node<T>* newNode = new Node<T>();
			newNode->data = data;
			this->tail->next = newNode;
			this->tail = this->tail->next;
			this->tail->next = this->head;
		}
	}

	/*void delete_(T data) //this function is not updated for circular link list
	{
		//if the list is empty
		if (this->head == nullptr)
			return;

		//if the element is found at head node.
		while (this->head->data == data)
		{
			Node<T>* deleteNode = this->head;
			this->head = this->head->next;
			delete deleteNode;
			this->totalElements--;

			if (this->head == nullptr)
			{
				this->tail = nullptr;
				return;
			}
		}

		Node<T>* curr = this->head;

		while (curr->next != nullptr)
		{
			if (curr->next->data == data)
			{
				Node<T>* deleteNode = curr->next;
				curr->next = curr->next->next;
				delete deleteNode;
				this->totalElements--;
				if (curr->next == nullptr)
				{
					this->tail = curr;
				}

			}
			else curr = curr->next;
		}
	}*/


	void deleteFromHead()
	{
		if (this->isEmpty())
			return;

		//if there was only one element in the list
		if (this->head == this->tail)
		{
			delete this->head;
			this->head = this->tail = nullptr;
			this->totalElements--;
			return;
		}

		Node<T>* delNode = this->head;
		this->head = this->head->next;
		delete delNode;
		this->tail->next = this->head;
		this->totalElements--;
		


	}

	void deleteFromTail()
	{
		if (this->isEmpty())
			return;

		if (this->head == this->tail) //if there is only one element in the list.
		{
			delete this->head;
			this->head = this->tail = nullptr;
			this->totalElements--;
		}

		else
		{
			Node<T>* curr = this->head;
			while (curr->next != this->tail)
			{
				curr = curr->next;
			}

			delete this->tail;
			this->tail = curr;
			this->tail->next = this->head;
			this->totalElements--;
		}
	}

	void print()
	{
		Node<T>* tmp = this->head;
	
		while (tmp != tail)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
		if (tmp)
			cout << tmp->data;
	}


	~CircularLinkList()
	{
		Node<T>* ptr;
		this->tail->next = nullptr;
		while (this->head)
		{
			ptr = this->head->next;
			delete this->head;
			this->head = ptr;
		}

	}
};