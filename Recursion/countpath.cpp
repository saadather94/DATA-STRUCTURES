#include <iostream>
using namespace std;

int countpath(int m, int n)
{
    if (m == 0 || n == 0)
    { 
          return 1;
    }

    int a = countpath(m - 1, n);
    int b = countpath(m, n - 1);

    return a+b;
}

int main()
{
    cout << countpath(1, 3);
    return 0;
}
