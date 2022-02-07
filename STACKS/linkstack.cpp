#include<iostream>
using namespace std;
#define size 99;

template<typename T>
class lstack
{
public:
    class node 
    {
        public:
        T data;
        node * next;

        node(){ this->data = data ;next = nullptr;}
        node(T val){ this->data = val; this->next = nullptr; }

    };

    node * top;
    int elem;


    lstack(){top = nullptr; elem =0;}

    bool isempty()
    {
        return top == nullptr;
    }

    bool isfull()
    {
        return elem == size-1;
    }

    void push(T value)
    {
        if(isfull())
        {
            return;
        }

        node * newnode = new node(value);
       
        newnode->next = top;
        top= newnode;
        elem++;
 

    }

    void pop()
    {
        if(isempty())
        { return;}

        node* newnode = top;
        top = top->next;
        delete newnode;
        elem--;

    }

    void print()
    {
        node *newnode = top;
 

        while(newnode)
        {
           
            cout<<newnode->data<<" ";
            newnode = newnode->next;

        }
    } 

    T Top()
    {
        return top->data;      
    }



};


int main(){

    lstack<int> ls;
    ls.push(2);
    ls.push(3);
    ls.push(4);
    ls.push(5);
    ls.push(6);
    ls.pop();
    ls.print();


}