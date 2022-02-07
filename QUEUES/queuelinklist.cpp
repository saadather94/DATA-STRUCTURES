#include<iostream>
using namespace std;

template <typename T>
class lqueue{

    class node
    {
    public:
        node()
        {   
            this->data = data;
            this->next=nullptr;

        }
        node(T value)
        {
            this->data = value;
            this->next = nullptr;
        }
        
        
            T data;
            node *next;
    };

public:
    node *front;
    node *rear;

    lqueue()
    {
        front = rear = NULL;
    }

 

    void enque(T value)
    {
        node * newnode = new node(value);

        if (rear == NULL)
        {
            front = rear = newnode;
            return;
        }

            rear->next = newnode;
            rear = newnode;
   
     
        
        return ;

    }

    void deque()
    {
        if (front == NULL)
        {
            return;
        }

        node * newnode = new node;
        newnode = front;
        front = front->next;
        delete newnode;

    }

    void print()
    {
        node * newnode = front;
        while(newnode)
        {
            cout<<newnode->data<<"  ";
            newnode= newnode->next;
        }
    }


};

int main()
{
    lqueue<int> q;
    q.enque(22);
    q.enque(266);
    q.enque(24);
    q.enque(23);
    q.enque(2);
    q.enque(255);
    q.deque();
    q.print();
}