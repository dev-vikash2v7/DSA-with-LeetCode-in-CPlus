#include <bits/stdc++.h>

using namespace std;

// time complexity = O(root(n))
// bool is_prime(int n)
// {
//     for (int i = 2; i <= sqrt(n) ;  i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

void SOE_prime(int n)
{
    int arr[n + 1] = {0};
    arr[1] = 1; // 1 is non-prime

    for (int i = 2; i <= sqrt(n); i++)
    {

        for (int j = 2 * i; j <= n; j += i)
        {
            arr[j] = 1;
        }
    }

    cout << "prime numbers are : \n";

    for (int i = 2; i <= n; i++)
    {
        if (!arr[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n = 50;
    // cout << is_prime(7) <<endl;;
    // cout << is_prime(8) <<endl;;
    // cout << is_prime(9) << endl;
    // cout << is_prime(13) << endl;

    // int arr[] = {};
    // int n = sizeof(arr) / 4;
    SOE_prime(n);

    return 0;
}

/*
Sieve of Erothesis : chante jao prime numbers ko

arr[] = {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17}

1.  let us assume all are prime number

2. start from 2 and mark all its multiple as false

3. start from 3 and mark all its multple as fase

4. comtinue till the end

5. now all the false elements are false

1 t
2 t
3 t
4 f
5 t
6 f
7 t
8 f
9 f
10 f
11 t
12 f
13 t
14 f
15 f
16 f
17 t


*/
