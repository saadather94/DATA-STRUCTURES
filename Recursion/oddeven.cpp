#include<iostream>
using namespace std;

void print(int * A)
{

    cout <<endl <<"EVEN ODD ARRAY :  ";
     for (int i = 1; i <= 10; i++)
    {
        cout<< A[i] << " ";

    }


}

void evenOdd(int *A, int size, int i, int j)
{

    if (size==-1)
    {   
        print(A);
        return;
    }

        if (A[i] % 2 == 0)
        {

            j++;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

        return evenOdd(A, size-1, i+1,j);

    }

int main()
{

    int size = 10;
    int * arr = new int[size];
    for (int i = 1; i <= size; i++) { arr[i]=i; }

    cout << "ORGINAL ARRAY : ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";

    }

    evenOdd(arr, size, 0,-1);

    delete[] arr;
    arr = NULL;

return 0;
}