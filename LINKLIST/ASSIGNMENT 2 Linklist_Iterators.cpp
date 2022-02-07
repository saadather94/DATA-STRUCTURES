#include<iostream>
using namespace std;

template <typename T>
class node
{
public:
	T data;
	node<T>* next;
	node<T>* prev;

	node() { next = nullptr; prev = nullptr;  }
	
	node(const T& item, node<T>* ptr = nullptr) 
	{ 
		data = item; 
		next = ptr; 
	}
};

// DoublyLinked list class
template <typename T>
class dlinklist
{
public:
	dlinklist()
	{
		// Create the dummy head node
		head = tail = new node<T>();
	}

	void insertlist(int data)
	{

		// node* entrynode=NULL;
		node<T>* newnode = new node<T>;

		newnode->data = data;
		newnode->next = head->next;
		head->next = newnode;
	}

	void insertathead(T data)
	{

		node<T>* newnode = new node<T>;

		newnode->data = data;
		newnode->next = head->next;
		newnode->prev = head;
		head->next = newnode;
	}

	void deleteathead()
	{

		if (head->next != nullptr)
		{

			node<T>* delnode = head->next;
			head->next = delnode->next;

			delete delnode;
		}
	}

	void deleteall(int data)
	{

		node<T>* curr = head->next;

		while (curr->data == data)
		{
			curr = curr->next;
		}

		while (curr->next != NULL)
		{
			if (curr->next->data == data)
			{
				curr->next = curr->next->next;
			}
			else
			{
				curr = curr->next;
			}
		}
	}

	void replaceall(int data, int newdata)
	{
		bool found = false;
		node<T>* prev = head;
		node<T>* next = head;

		node<T>* curr = new node<T>;
		curr->next = head->next;

		while (curr->next != NULL)
		{

			if (curr->data == data)
			{
				found = true;
			}
			else
			{
				curr = curr->next;
			}

			if (found)
			{
				curr->data = newdata;
				curr = curr->next;
			}
		}
	}

	void swapnodes(int nodex, int nodey)
	{
		if (nodex == nodey)
		{ // Nothing to do if nodex and nodey are same
			return;
		}

		node<T>* prevX = NULL, * currX = head; // Search for nodex (keep track of prevX and CurrX
		while (currX && currX->data != nodex)
		{
			prevX = currX;
			currX = currX->next;
		}

		node<T>* prevY = NULL, * currY = head; // Search for nodey (keep track of prevY and CurrY
		while (currY && currY->data != nodey)
		{
			prevY = currY;
			currY = currY->next;
		}

		if (currX == NULL || currY == NULL)
		{ // If either nodex or nodey is not present, nothing to do
			return;
		}

		// If nodex is not head of linked list
		if (prevX != NULL)
		{
			prevX->next = currY;
		}
		else
		{ // Else make nodey as new head
			head->next = currY;
		}

		// If nodey is not head of linked list
		if (prevY != NULL)
		{
			prevY->next = currX;
		}
		else
		{ // Else make nodex as new head
			head->next = currX;
		}

		// Swap next pointers
		node<T>* temp = currY->next;
		currY->next = currX->next;
		currX->next = temp;
	}

	void print()

	{

		node<T>* curr = new node<T>;
		curr = head->next;

		while (curr != NULL)
		{

			cout << curr->data;
			cout << " -> ";
			curr = curr->next;
			
		}
		cout << endl;
	}

	~dlinklist()
	{
		while (head->next != nullptr)
		{
			node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
	}



	// Inner class iterator
	class iterator
	{
		friend class dlinklist;

	private:
		// The constructor is private, so only our friends
		// can create instances of iterators.
		node<T>* nodePtr;
		iterator(node<T>* newPtr)
		 { 
			 nodePtr = newPtr;
		 }

	public:
		iterator() { nodePtr = nullptr; }

		// Overload for the comparison operators
		bool operator!=(const iterator& itr) const
		{
			return nodePtr != itr.nodePtr;
		}

		bool operator==(const iterator& itr) const
		{
			return nodePtr == itr.nodePtr;
		}

		// Overload for the dereference operator *
		T& operator*() const
		{
			return nodePtr->next->data;
		}

		// Overload for the pre/postincrement operator ++, --
		iterator& operator++()
		{
			nodePtr = nodePtr->next;
			return *this;
		}

		iterator  operator++(int)
		{
			iterator result(this->nodePtr);
			nodePtr = nodePtr->next;
			return result;
		}


		iterator& operator--()
		{
			nodePtr = nodePtr->prev;
			return *this;
		}

		iterator  operator--(int)
		{
			iterator result(this->nodePtr);
			nodePtr = nodePtr->prev;
			return result;
		}


	}; // End of inner class iterator

	iterator begin() const
	{
		return iterator(head);
	}

	iterator end() const
	{
		return iterator(tail);
	}

	iterator insert(iterator position, const T& value)
	{	
		node<T>* newNode = new node<T>(value, position.nodePtr->next);	
		
		if (position.nodePtr == tail){
			tail = newNode;	}
		position.nodePtr->next = newNode;
		return position;
	}

	iterator erase(iterator position)
	{
		node<T>* toDelete = position.nodePtr->next;
		position.nodePtr->next = position.nodePtr->next->next;
		if (toDelete == tail) {
			tail = position.nodePtr;}
		delete toDelete;
		return position;
	}

	iterator search(const T& value)
	{
		int pos = 0;
		bool found = false;

		node<T>* temp = head;

		while (temp != NULL && !found)
		{
			if (temp->data == value){

				cout << endl << temp->data
				 << " found at Iter poition " << pos<<endl;

				found = true;
			}
			temp = temp->next;
			pos++;
		}
		return temp;
	}



private:
	node<T>* head;
	node<T>* tail;
};

int main()
{

	dlinklist<int> obj;
	cout << endl
		<< "INSERTED NEW LIST is" << endl;
	obj.insertlist(1);
	obj.insertlist(2);
	obj.insertlist(2);
	obj.insertlist(7);
	obj.insertlist(3);
	obj.insertlist(6);
	obj.print();

	cout << endl
		<< "INSERTING ELEMENT AT HEAD " << endl;
	obj.insertathead(12);
	obj.print();

	cout << endl
		<< "AFTER DELETING ELEMENT AT HEAD " << endl;
	obj.deleteathead();
	obj.print();

	cout << endl
		<< "AFTER REPLACING ALL 2 with 99 " << endl;
	obj.replaceall(2, 99);
	obj.print();

	cout << endl
		<< "DELETING ALL GIVEN ELEMENT 99" << endl;
	obj.deleteall(99);
	obj.print();

	cout << endl
		<< "SWAPPING GIVEN ELEMENTs 1 & 3" << endl;
	obj.swapnodes(1, 3);
	obj.print();



	cout << endl << "/////////////////////////////////////////////////////////////////////////" << endl;
	cout << endl << "IMPLEMENTING USING ITERATORS BELOW: " << endl;




	dlinklist<int> v;

	cout << "inserting values " << endl;

	v.insert(v.end(), 2);
	v.insert(v.end(), 4);
	v.insert(v.end(), 5);
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	auto iter = v.begin();
	

	cout << endl << "Insert 1 before 2" << endl;
	iter = v.insert(iter, 1);								 // Insert 1 before 2
	iter++;					  								 // Points to 2
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;



	cout << endl << "Insert 3 before 2, advance to 4" << endl;
	v.insert(iter++, 3);	 								 // Insert 3 before 2, advance to 4
	iter++;				 									 // Points to 5
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;



	cout << endl << "insert 10 after 4" << endl;
	v.insert(iter, 10);										  // Insert 10 before 5
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	++iter;

	cout << endl << "insert multiple before 5" << endl;
	v.insert(iter, 100);
	v.insert(iter, 99);									//inserting multiple after the iterator points
	v.insert(iter, 89);
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	iter = v.begin();
	
	cout << endl << "Points to 3 and delete 3" << endl;
	iter++;		  											 // Points to 3
	v.erase(iter);											 // Erase 3
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;


	cout << "DELETING Multiple after 1" << endl;
	v.erase(iter);										// Deleting multiple after the next iterator position of 3 
	v.erase(iter);
	v.erase(iter);
	
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	v.search(99);


	return 0;
}