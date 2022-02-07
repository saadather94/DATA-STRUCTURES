
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return false;
}

int main(void)
{
    int arr[] = {5, 8, 11, 20, 25};
    
    int x = 25;

    int n = sizeof(arr) / sizeof(arr[0]);
    
    int a = binarySearch(arr, 0, n - 1, x);

    if(a == 0) {
        cout << "Element is not present in array";}
        else{
        cout << "Element is present at index " << a;}
   
    return 0;
}
