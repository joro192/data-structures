#include <iostream>

using namespace std;

int n = 3;
char A[3];

void Binary(int n)
{
    if (n < 1)
        printf("%s\n", A);
    else
    {
        A[n - 1] = '0';
        Binary(n - 1);
        A[n - 1] = '1';
        Binary(n - 1);
    }
}

int main()
{
    Binary(n);
    return 0;
}