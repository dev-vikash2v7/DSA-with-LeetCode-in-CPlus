#include <bits/stdc++.h>

using namespace std;

void bitrep(int n)
{
    if (n == 0 || n == 1)
    {
        cout << n;
        return;
    }
    bitrep(n / 2);
    cout << n % 2;
}

// time complexity = O(log n )
// no of bits : O(log n) + 1

// void convert(int a, int b)
// {
//     //using xor to give result of 1's of changing bits only
//     int result = a ^ b;

//     cout << result << " ";
//     bitrep(result);
//     cout << endl;

//     int c = 0;

//     while (result)
//     {
//         if (result % 2 == 1)
//         {
//             c++;
//         }
//         result = result >> 1;
//     }
//     cout << "count to change " << c << endl;
// }

//time complexity = O(no of setbits in (a^b))
void convert(int a, int b)
{
    int result = a ^ b;

    cout << result << " ";
    bitrep(result);
    cout << endl;

    int c = 0;

    while (result)
    {
        c++;
        result = result & (result - 1);
        bitrep(result);
        cout << endl;
    }

    cout << "count to change " << c << endl;
}

int main()
{
    int a = 22;
    int b = 27;

    bitrep(a);
    cout << endl;
    bitrep(b);
    cout << endl;

    convert(a, b);

    return 0;
}

/*
5 & 4 (101 & 100) = 100
4 & 3 (100 & 011) = 000
total operation = no of bits = 2

22(10110) -> 27(11011)
result (a ^ b) = 13(1101)

13 & 12 (1101 & 1100) = 12( 1100 )
12 & 11 (1100 & 1011) = 8 (1000)
8  & 7 (1000 & 0111) = 0
total operation = no of bits = 3
*/