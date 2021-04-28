#include <iostream>

using namespace std;

void TowersOfHanoi(int n, char frompeg, char topeg, char auxpeg)
{
    // if only 1 disk, make the move and return
    if (n == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }

    // Move top n-1 disks from A to B, using C as auxilary
    TowersOfHanoi(n - 1, frompeg, auxpeg, topeg);

    // Move remaining disks from A to C
    printf("\nMove disk %d from peg %c to peg %c", n, frompeg, topeg);

    // Move n-1 disks from B to C using A as auxilary
    TowersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}

int main()
{
    TowersOfHanoi(4, 'A', 'B', 'C');
    return 0;
}