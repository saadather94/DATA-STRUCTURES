#include<iostream>
using namespace std;
#define size 10

template<typename T>
class queue
{
public:
  int front;
  int rear;
  int item;
  int * arr;

  queue()
  {
    front=0;
    rear=0;
    item=0;
    arr = new int[size];
  }

  bool isempty()
  {
    return item ==0;
  }
  bool isfull()
  {
    return item == size;
  }

  void enque(T value)
  {
    if(isfull()) {return;} // nothing

    arr[rear] = value;
    rear = (rear+1)%size;
    item++;
    
  }

  T deque()
  {
   if(isempty()) {return false;} // nothing

    T var = arr[front]; // variable
    front = (front +1)%size;
    item--;
    return var;

  }

  void print()
  {
    int i=0;
    while(i!=item)
    {

      cout<<arr[i]<<" ";
      i++;
    }
  }

};


template<typename S>
class stack
{
  int item;
  public:

  stack()
  {
    item=0;
  }

  queue<int> q1, q2;
  


  void push(S data)
  {

    if(q1.isempty())
    {
      q1.enque(data);
      item++;
    }

    while(!q1.isempty())
    {
      int temp = q1.deque();
      q2.enque(temp);
    }

    q1.enque(data);
    item++;

    while(!q2.isempty())
    {
      int temp = q2.deque();
      q1.enque(temp);
    }
  }

  void pop()
  {
    q1.deque();
    item--;
  }

  void print()
  {
    q1.print();
  }


};





int main(){

  stack<int> s;
  s.push(1);
  s.push(3);
  s.push(4);
  s.push(5);
  s.pop();

  s.print();



  return 0;
}