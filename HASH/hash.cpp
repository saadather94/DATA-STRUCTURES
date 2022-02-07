#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
// 
//     int i = 1;
//     int hash1 = key % tablesize; /// hash func 1

//     int hash2 = prime - (key % prime); /// hash func 2

//     int index = (hash1 + i) % tablesize; /// linear probing

//     int index1 = (hash1 + i * i) % tablesize; /// quadritic probing

//     int index2 = (hash1 + i * hash2) % tablesize; /// double hashing
// 
////////////////////////////////////////////////////////////////////////////////


///////////////////////////hash table seperate chaining/////////////////////////////////

struct node
{
    int key;
    node* next;
};

struct list
{
    node* head;
};

class htable
{
    list *table;
    int tablesize;
    int prime;

public:

    htable()
    {   
        tablesize = 5;
        prime =7;
        table = new list[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
            table[i].head = NULL;
        }
        
    }

    node * new_node(int key)
    {
        node * newnode = new node;
        newnode->key =key;
        newnode->next=NULL;
        return newnode;
    }
    
    void insert(int k)
    {
        int hash1 = (k % tablesize);
        int hash2 = prime - (k % prime);

        if(table[hash1].head != NULL)
        {
            node * newnode = new_node(k);
            newnode->next = table[hash1].head;
            table[hash1].head = newnode;
        }
        else
        {
            table[hash1].head = new_node(k);
        }
    }

    void print()
    {
        cout << endl;
        for (int i = 0; i < tablesize; i++)
        {
            node *ptr = table[i].head;

            cout << "index " << i << ": ";

            while (ptr)
            {
                cout << "->" << ptr->key << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};





int main(){

    htable h;
    h.insert(1);
    h.insert(2);
    h.insert(17);
    h.insert(15);
    h.insert(8);
    h.insert(16);
    h.insert(6);
    h.insert(9);
    h.insert(12);

    h.print();


  return 0;
}
