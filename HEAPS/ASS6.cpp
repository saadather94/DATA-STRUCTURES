#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;
int size = 0;


struct node
{
    char key;
    int value;
    node *left, *right;

    node()
    {
        left = right = nullptr;
    }
};

class priority_qeuee
{
private:
    node *arr;
    int index;
    int capacity;

public:
    priority_qeuee()
    {

        capacity = 200;
        arr = new node[capacity];
        index = 1;
    }

    node top()
    {
        return arr[1];
    }

    int size()
    {
        return index - 1;
    }

    void doubleCapacity()
    {

        node *oldArr = arr;

        int double_ = capacity * 2;

        arr = new node[double_];

        for (int i = 0; i < double_; i++)
        {
            arr[i] = oldArr[i];
        }

        delete[] oldArr;
    }

    void push(char _key, int _value)
    {
        if (index != capacity)
        {
            node _new;
            _new.key = _key;
            _new.value = _value;

            arr[index] = _new;
            index++;
            heapify(arr, index - 1);
        }
        else
        {
            doubleCapacity();
            push(_key, _value);
        }
    }

    void heapify(node *arr, int i)
    {
        int parent = i / 2;

        if (i == 1)
        {
            return;
        }

        if (arr[parent].value > arr[i].value)
        {
            node temp;

            temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;

            heapify(arr, i / 2);
        }
    }

    void heapify_down(node *arr, int i)
    {
        int parent = i;
        int l = 2 * i;     // left = 2*i
        int r = 2 * i + 1; // right = 2*i + 1

        if (l < index && arr[i].value > arr[l].value)
        {
            parent = l;
        }
        if (r < index && arr[i].value > arr[r].value)
        {
            parent = r;
        }

        if (parent != i)
        {
            node temp;

            temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;

            heapify_down(arr, parent);
        }
    }

    void pop()
    {
        delete_(arr, index);
    }

    void delete_(node *arr, int i)
    {

        if (index == 0)
        {
            return;
        }

        node temp;
        temp = arr[1];
        arr[1] = arr[index - 1];
        arr[index - 1] = temp;

        index--;

        heapify_down(arr, 1);

        return;
    }

    void print()
    {
        print(arr);
    }

    void print(node *arr)
    {
        for (int i = 1; i < index; i++)
        {
            cout << arr[i].key << ":"<<arr[i].value <<" ";
        }
    }

    ~priority_qeuee()
    {
        delete[] arr;
        capacity = 0;
        index = 0;
    }
};

int main()
{
    priority_qeuee h;

    int freq[128];   // frequencies of letters
    ifstream inFile; // input file
    char ch,ch2;
    int i;
    

    inFile.open("file.txt");
    if (!inFile)
    {
        cout << "The input file could not be opened." << endl;
        return 1;
    }

    for (int k = 0; k < 128; k++){freq[k] = 0;}

    while (inFile)
    {
        i = ch2;
        if ((i >= 65 && i <= 90) || (i >= 95 && i <= 122) || (i >= 48 && i <= 57))
        {
            freq[ch2]++;
            size++;
        }
        inFile.get(ch2);
    }

    for (char ch = 65; ch <= 90; ch++)
    {  
        if(freq[ch] != 0)
        {
           h.push(ch,freq[ch]);

        }
    }
    for (char ch = 95; ch <= 122; ch++)
    {
        if (freq[ch] != 0)
        {
            h.push(ch, freq[ch]);

        }
    }
    for (char ch = 48; ch <= 57; ch++)
    {
        if (freq[ch] != 0)
        {
            h.push(ch, freq[ch]);

        }
        
    }

   // cout<<size;

    h.print();
    //h.huffmanencoding();
    h.pop();
    cout<<endl;
    h.print();
 
    cout<<ch;
    return 0;
}