
#include <iostream>
using namespace std;

void subset(int arr[], int n, int r,
                     int index, int data[], int i);
void printsubset(int arr[], int n, int r)
{

    int data[r];

    subset(arr, n, r, 0, data, 0);
}

void subset(int arr[], int n, int r, int index,
                     int data[], int i)
{
    if (index == r)
    {
        cout << "{ ";
            for (int j = 0; j < r; j++)
        {
            cout << data[j] << " ";
        }
        cout << "}, ";
        return;
    }

    if (i >= n)
        return;

    data[index] = arr[i];
    subset(arr, n, r, index + 1, data, i + 1);
    subset(arr, n, r, index, data, i + 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6};
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printsubset(arr, n, r);
    return 0;
}

