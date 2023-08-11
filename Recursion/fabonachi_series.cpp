#include <iostream>

using namespace std;

int a = 0, b = 1;

int fab(int n)
{

    if (n == 0)
        return -1;

    cout << a << " ";

    int c = a + b;
    b = a;
    a = c;

    fab(n - 1);
}

int main()
{
    fab(6);
    return 0;
}
