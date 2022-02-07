#include<iostream>
using namespace std;


bool checksum(int *A, int size)
{
    if(size ==0){return false;}
    int temp = A[size-1]+A[size-2];
    if(A[size]==temp)
    {
        checksum(A, size-1);        
    }
    else{return false;}

    return true;

}



int main(){


    int size = 10;
    
    int *Arr = new int[size];
    
    Arr[-1] = 0, Arr[0]=1;
    for (int i = 1; i <= size; i++)
    {
        int j = Arr[i-2]+Arr[i-1];          // inserting values
        Arr[i] = j;
    }


    cout << "ORGINAL ARRAY : ";
    for (int i = 1; i <= size; i++)
    {
        
        cout << Arr[i] << " ";
    }

    bool a = checksum(Arr, size);


    if (a==1)
    {
        printf("TRUE");
    }
    else 
    {
     printf("FALSE");
    }

        delete[] Arr;
        Arr = NULL;

    return 0;
}