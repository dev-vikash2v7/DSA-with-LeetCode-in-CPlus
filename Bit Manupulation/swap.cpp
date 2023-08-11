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
void swap(int a, int b)
{
    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ;
    cout << "after swapped " << a << " " << b  << endl;
}

int main()
{
    int a = 22;
    int b = 27;

    bitrep(a);
    cout << endl;
    bitrep(b);
    cout << endl;

    swap(a, b);

    return 0;
}

/*
a=a^b = 22(10110) ^ 27(11011) =  01101(11)
b=a^b = 11(01101) ^ 27(11011) =  10110(22)
a=a^b = 22(01101) ^ 27(11011) =  11011(27)


*/