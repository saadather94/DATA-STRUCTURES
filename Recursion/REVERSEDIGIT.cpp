#include<iostream>
using namespace std;

int reversDigits(int num, int &power )
{

    if (num == 0)
    {return power;}

    power = power * 10 + num % 10;
    num = num / 10;

    return reversDigits(num,power);
}

int main()
{
    int num = 12345, power = 0;
    cout << "Reverse of 12345 is " << reversDigits(num, power);
    return 0;
}
