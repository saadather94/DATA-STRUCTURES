#include<iostream>
using namespace std;

struct hnode
{
  int key;
  int value;
  hnode *next;

};

class Heap
{
private:

int index;
hnode * arr;
int capacity;

public:
  Heap(int c)
  {
    capacity = c;
    arr = new hnode[capacity];
    index = 1;
  }

  hnode new_node(int k, int v)
  {
    hnode newnode;
    newnode.next = nullptr;
    newnode.key = k;
    newnode.value = v;
    return newnode;
  }

  void insert(int k, int v)
  {
    hnode newnode = new_node(k,v);

      arr[index] = newnode;
      index++;
      heapify(index-1);
    
  }

  void heapify(int index)
  {
    if(index==1)
    {
      return;
    }

    int parent = index/2;

    if(arr[index].key>arr[parent].key)
    {
      hnode temp = arr[index];
      arr[index] = arr[parent];
      arr[parent] = temp;
    }

    heapify(index/2);
  }

  void del()
  {
    hnode temp;
    temp = arr[1];
    arr[1]= arr[index];
    arr[index] = temp;	
    index--;

    bottomdown(1);
  }

  void bottomdown(int index)
  {
    int max = index;
    int lchild = 2 * index ;
    int rchild = 2 * index + 1;

    if (lchild > index && arr[lchild].key>arr[max].key)
    {
      max =lchild;
    }
    if (rchild > index && arr[rchild].key > arr[max].key)
    {
      max = rchild;
    }

    if (index!=max)
    {
      hnode temp;

      temp = arr[max];
      arr[max] = arr[index];
      arr[index] = temp;

      bottomdown(max);

    }
  }

  void print()
  {
    for (int i = 1; i < index; i++)
    {
      cout<<arr[i].key<<" ";
    }  
  }


  ~Heap(){ delete [] arr; }
};




int main(){


  Heap h(6);
  h.insert(1,2);
  h.insert(2, 1);
  h.insert(5, 3);
  h.insert(7, 3);
  h.insert(3, 3);
  h.print();

  cout<<endl;
  h.del();
  h.print();	


  return 0;
}