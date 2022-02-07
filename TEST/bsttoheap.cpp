#include<iostream>
using namespace std;

struct node
{
    int key;
    node* left;
    node* right;

    // node(){left=nullptr; right=nullptr;}
    // node(int k){left=nullptr; right=nullptr; key=k;}
};


class minheap
{
private:
    int cap;
    int index;
    node * arr;

public:
    minheap(int c)
    { 
        cap = c; 
        arr = new node[cap]; 
        index=1; 
        for (int i = 0; i < cap; i++)
        {
            arr[i].key = 0;
        }
    }
    
    void BstToHeap(int i)
    {
        if(index==1)
        {
            arr[index].key = i;
            index++;
        }
        else
        {
            arr[index].key = i;
            index++;
        }

        //cout<<arr[index].key<<" ";

        heapify(index-1);
        
    }

    void swap(int i, int j)
    {   
        node temp;
        temp = arr[j];
        arr[j]=arr[i];
        arr[i] = temp;    
    }

    void heapify(int index)
    {
        int parent = index/2;
        
        if(arr[parent].key<arr[index].key)
        {
            swap(parent, index);
        }

        if(index==1)
        {return;}

        heapify(index/2);

    }


    void print()
    {
        cout<<"arr[]= {";
        for (int i = 1; i < index; i++)
        {
            cout<<arr[i].key<<", ";
        }
        cout<<"}";

    }

    ~minheap() {delete [] arr;}
};

class bst
{
private:

node * root;

public:
    bst()
    {
        root = nullptr;
    }
    	
    node * new_node(int key)
    {   
        node * newnode = new node;
        newnode->key = key;
        newnode->left = nullptr;
        newnode->right = nullptr;
        return newnode;



    }

    void bstinsert(int k)
    {
        bstinsert(root,k);
    }

    void bstinsert(node *& root ,int k)
    {
        if (root == nullptr)
        {
            root = new_node(k);

        }

        else if(root->key>k)
        {
            bstinsert(root->left,k);
        }
        else if (root->key < k)
        {
            bstinsert(root->right, k);
        }
        
    }

    void convert()
    {
        convert(root);
    }

    void convert(node * root)
    {
        minheap h(10);

        if(root)
        {
            convert(root->left);
            //h.BstToHeap(root->key);
            convert(root->right);
        }
        
    }

    ~bst(){}
};


int main(){


int arr[] = {20,2,1,10,4,11};
int size = sizeof(arr)/sizeof(arr[0]);
minheap h(size);
bst b;
for (int i = 0; i < size; i++)
{
    int u = arr[i];
    //b.bstinsert(u);
    h.BstToHeap(u);
}

//b.convert();
h.print();

cout<<endl;

  return 0;
}