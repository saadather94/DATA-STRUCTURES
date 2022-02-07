#include <iostream>
using namespace std;


struct Node
{
	int data;
	struct Node *next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList
{
	Node *head;
	LinkedList()
	{
		head = NULL;
	}

	Node *reverse(Node *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		Node *rev = reverse(head->next);
		
		head->next->next = head;

		head->next = NULL;

		return rev;
	}


	void print()
	{
		struct Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void insert(int data)
	{
		Node *temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};


int main()
{
	LinkedList list;
	list.insert(3);
	list.insert(2);
	list.insert(1);
	list.insert(9);
	list.insert(4);
	list.insert(5);
	list.insert(6);

	cout << "Given linked list\n";
	list.print();

	list.head = list.reverse(list.head);

	cout << "\nReversed Linked list \n";
	list.print();
	return 0;
}
