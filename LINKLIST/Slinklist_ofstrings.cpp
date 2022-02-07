#include<iostream>
#include <cstring>
using namespace std;

template<typename T>
class list
{
   
    class node{

        T data;
        node * next;
        friend class list;

    public:
        node()
        {
            this->data = data;
            next = nullptr;
        }
        node(T value)
        {
            this->data=value; 
            next = nullptr;
        }
    };

    node * head;
    node * tail;

public:
    list()
    {
        head=nullptr;
        tail= nullptr;
    }

    
    void insert(char *text)
    {
        int b=strlen(text);
    
        node *newnode = new node;
        newnode->data = text[0];
        newnode->next = NULL;
        head = newnode;

  
        node *curr = head;
        
        for (int i = 1; i < b; i++)
        {

            node *newnode = new node;
            newnode->data = text[i];
            newnode->next = NULL;
            curr->next = newnode;
            
            curr =  curr->next;
            
        }

    }

    void print()
    {   
        node * newnode = head;
        while(newnode)
        {
            cout<<newnode->data<<" -> ";
            newnode=newnode->next;
        }


    }

};





int main(){

    char a[] = "PAKISTAN";
    list<char> l;
    l.insert(a);
    l.print();
    




  return 0;
}