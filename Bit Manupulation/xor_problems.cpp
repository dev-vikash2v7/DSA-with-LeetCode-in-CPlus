#include <bits/stdc++.h>

using namespace std;

// find only non repeating element in an aray where every element repeats twice
// void func(int arr[], int n)
// {
//     int non_rep = 0 ;
//     for (int i = 0; i < n; i++)
//     {
//         non_rep = non_rep ^ arr[i] ;
//     }
//     cout << non_rep << endl;
// }

// find only two non-repeating element in an aray where every element repeats twice
// void func(int arr[], int n)
// {
//     int non_rep = 0;

//     for (int i = 0; i < n; i++)
//     {
//         non_rep = non_rep ^ arr[i];
//     }
//     cout << non_rep << endl;
// }

// find only one non-repeating element in an aray where every element repeats thrice
void func(int arr[], int n)
{
    int setbits_freq[32] = {0};

    int non_rep = 0;

    for (int i = 0; i < n; i++)
    {
        // setbits_freq[ ]  ++;
    }
    cout << non_rep << endl;
}

// find only one non-repeating element in an aray where every element repeats k times
void func(int arr[], int n)
{
    int setbits_freq[32] = {0};

    int non_rep = 0;

    for (int i = 0; i < n; i++)
    {
        // setbits_freq[ ]  ++;
    }
    cout << non_rep << endl;
}

int main()
{
    // int arr[] = {5 , 4 , 1 ,4 , 2 , 5 , 1 , 9};
    int arr[] = {2, 2, 1, 5, 1, 1, 2};
    int n = sizeof(arr) / 4;

    func(arr, n);

    return 0;
}

/*
0 ^ n  = n
n ^ n =  0
n ^ n ^ m = m

a ^ b =res
a = res ^ b
b = res ^ a

-----------------------

q1 ) find only non repeating element in an aray where every element repeats twice
. {5 , 4 , 1 ,4 , 2 , 5 , 1 };

 => non_rep = 0 ^ 5 ^ 4 ^ 1 ^ 4 ^ 2 ^  5 ^ 1
 => non_rep = 0 ^ 2 = 2




 --------

1001
0010
----


q2 )  find only two non-repeating element in an aray where every element repeats twice

{5 , 4 , 1 ,4 , 2 , 5 , 1 , 9}

non_rep = 0 ^ 5 ^ 4 ^ 1 ^ 4 ^ 2 ^  5 ^ 1
non_rep = 2 ^ 9
non_rep = 1011

non_rep last most setbit pos is 0
therefor at 0th index position of both a & b is different
now we divide array into two parts where 1 group 0 index is setbit and not set bit

group 1 => 0 index is 1(odd) => {5 , 1 ,  5 , 1 , 9}
group 2 => 0 index is 0(even) => {4 , 4 ,  2}

non_rep ^ group1 => { non_rep ^ 5 ^ 1 ^ 5 ^ 1 ^ 9  } => {non_rep ^ 9} = 2
a = 2

b = a ^ res
b = 2 ^ non_rep
b = 9

our two elements non_rep are 2 & 9

--------------------


q3.

{2, 2, 1, 5, 1, 1, 2}

2 => 10 => 2 & 1 =>   
*/