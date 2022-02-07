
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
  T data;
  Node<T> *next;
};

template <typename T>
class LinkList
{
private:
  Node<T> *head;
  Node<T> *tail;

  int totalElements;

public:
  LinkList()
  {
    this->head = nullptr;
    this->tail = nullptr;
    this->totalElements = 0;
  }

  LinkList(LinkList &obj)
  {

    Node<T> *newNode = new Node<T>;
    newNode->head = obj.head;
    newNode->tail = obj.tail;
    
    while(obj)
    {
      newNode->data = obj.data;
      newNode->next = obj.next;
    }

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
      this->head->next = nullptr;
      totalElements++;
    }

    else
    {
      Node<T> *newNode = new Node<T>;
      newNode->data = data;
      newNode->next = this->head;
      this->head = newNode;
      totalElements++;
    }
  }

  void insertAtTail(T data)
  {
    if (this->isEmpty()) // if list is empty.
    {
      Node<T> *newNode = new Node<T>;
      newNode->data = data;
      newNode->next = nullptr;
      this->head = this->tail = newNode;
      totalElements++;
    }
    else
    {
      this->tail->next = new Node<T>;
      this->tail->next->data = data;
      this->tail->next->next = nullptr;
      this->tail = this->tail->next;
      totalElements++;
    }
  }

  void delete_(T data)
  {
    // if the list is empty
    if (this->head == nullptr)
      return;

    // if the element is found at head node.
    while (this->head->data == data)
    {
      Node<T> *deleteNode = this->head;
      this->head = this->head->next;
      delete deleteNode;
      this->totalElements--;

      if (this->head == nullptr)
      {
        this->tail = nullptr;
        return;
      }
    }

    Node<T> *curr = this->head;

    while (curr->next != nullptr)
    {
      if (curr->next->data == data)
      {
        Node<T> *deleteNode = curr->next;
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

  void deleteFromHead()
  {
    if (this->isEmpty())
      return;

    // if there was only one element in the list
    if (this->head == this->tail)
    {
      delete this->head;
      this->head = this->tail = nullptr;
      this->totalElements--;
      return;
    }

    Node<T> *delNode = this->head;
    this->head = this->head->next;
    delete delNode;
    this->totalElements--;
  }

  void deleteFromTail()
  {
    if (this->isEmpty())
      return;

    if (this->head == this->tail) // if there is only one element in the list.
    {
      delete this->head;
      this->head = this->tail = nullptr;
      this->totalElements--;
    }

    else
    {
      Node<T> *curr = this->head;
      while (curr->next != this->tail)
      {
        curr = curr->next;
      }

      delete this->tail;
      this->tail = curr;
      this->tail->next = nullptr;
      this->totalElements--;
    }
  }

  void print()
  {
    Node<T> *tmp = this->head;
    while (tmp)
    {
      cout << tmp->data << " -> ";
      tmp = tmp->next;
    }
  }

  bool dellast(int k)
  {
    bool found = false;
    bool done= false;
    Node<T> *tem = head;

    if (tem == nullptr && !found)
    {
      return false;
    }
    Node<T> * prev =nullptr;
    Node<T> * curr = nullptr;
    Node<T> * snext = nullptr;

    while (tem->next!= nullptr && !done)
    {

      if (tem->next->data == k && tem->next!=nullptr)
      {
        prev = tem;
        curr = tem->next;
        snext = curr->next;
        found = true;
      }

      if (tem->next== nullptr)
      {
        cout << "11";
        prev->next = snext;
        snext->next= curr->next->next;
        cout<<prev->data;
        done = true;
        //curr->next = nullptr;
        
        delete curr;
        curr = nullptr;
      }

      tem = tem->next;

    }
    return false;

  }


  ~LinkList()
  {
    Node<T> *ptr;
    while (this->head)
    {
      ptr = this->head->next;
      delete this->head;
      this->head = ptr;
    }
  }
};

int main()
{

  LinkList<int> l;
  l.insertAtHead(7);
  l.insertAtHead(6);
  l.insertAtHead(5);
  l.insertAtHead(4);
  l.insertAtHead(3);
  l.insertAtHead(7);

//  l.deleteFromHead();
  l.insertAtHead(4);
  l.insertAtHead(1);

  LinkList<int> l2;
  //l2 = l;

  //l.delete_(1);
  l.print();
  cout<<endl;

  //l2.print();

  if(l.dellast(4))
  {
    cout<< "1";
  }
  l.print();


}