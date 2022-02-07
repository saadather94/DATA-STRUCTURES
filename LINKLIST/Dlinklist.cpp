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
	public:
	DNode<T>* head;
	DNode<T>* tail;
	int totalElements;

public:
	DLinkList()
	{
		this->head = this->tail = nullptr;
		this->totalElements = 0;
	}

	bool isEmpty()
	{
		return !this->head;
	}

	void insertAtHead(T data)
	{

		if (isEmpty())
		{
			DNode<T>* newNode = new DNode<T>;
			newNode->data = data;
			newNode->next = nullptr;
			newNode->prev = nullptr;
			this->head = this->tail = newNode;
			totalElements++;
		}
		else
		{
			DNode<T>* newNode = new DNode<T>;
			newNode->data = data;
			newNode->next = this->head;
			newNode->prev = nullptr;
			this->head->prev = newNode;
			this->head = newNode;
			totalElements++;
		}
	}

	void insertAtTail(T data)
	{
		if (isEmpty())
		{
			DNode<T>* newNode = new DNode<T>;
			newNode->next = newNode->prev = nullptr;
			newNode->data = data;
			this->head = this->tail = newNode;
			this->totalElements++;
		}
		else
		{
			DNode<T>* newNode = new DNode<T>;
			newNode->data = data;
			newNode->next = nullptr;
			newNode->prev = this->tail;
			this->tail->next = newNode;
			this->tail = newNode;
			this->totalElements++;
		}
	}

	void deleteFromTail()
	{
		if (isEmpty())
		{
			return;
		}

		if (this->head == this->tail)
		{
			delete head;
			this->head = this->tail = nullptr;
			this->totalElements--;
		}
		else
		{
			DNode<T>* delNode = this->tail;
			tail=tail->prev;
			tail->next = nullptr;
			delete delNode;
			this->totalElements--;
		}
	}

	void deleteFromHead()
	{
		if (isEmpty())
		{
			return;
		}

		if (this->head == this->tail)
		{
			delete head;
			this->head = this->tail = nullptr;
			this->totalElements--;
		}

		else
		{
			DNode<T>* delNode = this->head;
			head = head->next;
			head->prev = nullptr;
			delete delNode;
			this->totalElements--;
		}
	}

	void print()
	{
		DNode<T>* tmp = head;
		while (tmp)
		{
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void delete_(T data)
	{
		// if the list is empty
		if (this->head == nullptr)
			return;

		// if the element is found at head node.
		while (this->head->data == data)
		{
			DNode<T> *deleteNode = this->head;
			this->head = this->head->next;
			delete deleteNode;
			this->totalElements--;

			if (this->head == nullptr)
			{
				this->tail = nullptr;
				return;
			}
		}

		DNode<T> *curr = this->head;

		while (curr->next != nullptr)
		{
			if (curr->next->data == data)
			{
				DNode<T> *deleteNode = curr->next;
				curr->next = curr->next->next;
				delete deleteNode;
				this->totalElements--;
				if (curr->next == nullptr)
				{
					this->tail = curr;
				}
			}
			else
				curr = curr->next;
		}
	}

	DNode<T> *reverse(DNode<T> *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		DNode<T> *rest = reverse(head->next);
		head->next->next = head;

		head->next = NULL;

		return rest;
	}

	~DLinkList()
	{
		DNode<T>* ptr = this->head;
		while (head)
		{
			ptr = ptr->next;
			delete head;
			head = ptr;
		}

	}
};

int main()
{

	DLinkList<char> obj;

	obj.insertAtHead('A');
	obj.insertAtHead('F');
	obj.insertAtHead('N');
	obj.print();

	obj.head = obj.reverse(obj.head);
	obj.print();

	obj.insertAtHead('A');
	obj.insertAtHead('F');
	obj.insertAtHead('N');
	obj.insertAtHead('U');
	obj.insertAtHead('T');
	obj.insertAtTail('P');
	obj.print();

	obj.delete_('P');
	obj.delete_('F');
	obj.print();

	return 0;
}