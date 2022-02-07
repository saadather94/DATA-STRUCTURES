#include <iostream>
using namespace std;

template <class T>
class queue
{
private:
    struct node
    {
        T data;
        struct node *next;
    };
    struct node *head, *front, *rear;

public:
    queue()
    {
        head = new node;
        head->next = NULL;
        front = rear = head;
    }

    void enqueue(T x)
    {
        node *p;
        p = new node;
        p->data = x;
        if (head->next == NULL)
        {
            front = rear = p;
            head->next = p;
            p->next = p;
        }
        else
        {
            rear->next = p;
            p->next = front;
            rear = rear->next;
        }
    }

    T dequeue()
    {
        node *t;
        T x;
        t = front;
        x = t->data;
        front = front->next;
        rear->next = front;
        delete (t);
        return x;
    }

    void move_next()
    {
        front = front->next;
        rear = rear->next;
    }

    void print()
    {
        node *p = front;
        do
        {
            cout << p->data << "  ";
            p = p->next;
        } while (p != rear->next);
    }
};

int main()
{
    queue<int> obj;

    int skipord, peps, i, win;
    cout << "Enter the number of people 'n' : ";
    cin >> peps;
    cout << "Enter the skipping order 'k' : ";
    cin >> skipord;
    for (i = 1; i <= peps; i++)
    {
        obj.enqueue(i);
    }

    cout << "The players are :" << endl;

    obj.print();

    cout << endl
         << "Eliminated in order: " << endl;

    while (peps > 1)
    {
        for (i = 1; i < skipord; i++)
        {
            obj.move_next();
        }
        win = obj.dequeue();
        cout << win << endl;
        peps--;
    }

    win = obj.dequeue();
    cout << "Winning player:	" << win << endl;

    return 0;
}
