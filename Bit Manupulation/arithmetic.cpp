#include <bits/stdc++.h>

using namespace std;

void bitrep(int n)
{
    string bin = "";
    int i = 0;
    while (n)
    {
        /* code */
        bin += to_string(n % 2);
        // 1 * 1 * 0
        n = n >> 1;//dividing by 2 n/2
        // i++;
    }
    reverse(bin.begin(), bin.end());
    cout << bin << endl;
}

void modulo(int a){
    cout << "remainder with 2 is " << (a & 1 )<< endl;
}


void even_odd(int a){
    if(a & 1 == 0){
        cout << "even \n";
    }
    else{
        cout << "odd \n";

    }
}

int main()
{
    int a = 5, b = 9;
    // bitrep(a);
    // bitrep(b);

    cout << a << endl;

// cout<<"2's complement (negative of number) " << endl;

//     cout << ~(1) + 1 << endl;
//     cout << ~(2) + 1 << endl;
//     cout << ~(3) + 1 << endl<<endl;;
//     cout << ~(-1) + 1 << endl;
//     cout << ~(-2) + 1 << endl;
//     cout << ~(-3) + 1 << endl;

cout << "right shift to double the number \n";
cout << (50 << 0) <<endl;
cout <<( 50 << 1 )<<endl;
cout <<( 50  << 2) <<endl;
cout << (50  << 3) <<endl;
cout << (50  << 4) <<endl;
cout << (50  << 5) <<endl;

cout << "left shift to double the number \n";
cout << (50 >> 0) <<endl;
cout <<( 50 >> 1 )<<endl;
cout <<( 50  >> 2) <<endl;
cout << (50  >> 3) <<endl;
cout << (50  >> 4) <<endl;
cout << (50  >> 5) <<endl;

    // div(a , b);
    // mul(a , b);
    modulo(a );
    modulo(b );
    modulo(4 );

even_odd(a) ;
    return 0;
}

/*
5 + 9 = 14
//note
1 + 1 = 10 (2)
1 + 1 + 1 = 11(3)
1 + 1 + 1  + 1 = 100(4)

    1
  0101
+ 1001
------
  1110
------


9 - 7 = 2
9  +  (-7) = 2

## negative inverse of any number is 2's compliment
steps : 1. invert all bits
        2. add one

7(111)
invert all bits : ..1111111000
add one  : ..1111111000 + 1 => ...1111111001
2's compplimet of 7 is : ...1111111001

9 + (-7) =>

  1001
+ 1001
------
  ...00000010 = (2)


(-8) + (-12) => -20

-8 => 2's complement of 8  = ...11110111 + 1 => .11111000

 11110111
 00000001
 --------
 11111000

--------------------

-12 => 2's complement of 12 => 00001100 => 11110011 + 1 => 11110100

-8 => 11111000
-12 => 11110100

-8 + (-12) =>
  11111000
+ 11110100
------------
  ..111101100

-8 + -12 = 11101100

  1001
+ 1001
------
  ...00000010 = (2)


  -------------------

  right shift to double the number

50
100
200
400
800
1600

left shift to double the number
50
25
12
6
3
1

----------------------

modulo 

# last bit  of even is always 0
2  10
4  100
6  110
8  1000
10 1100


# last bit  of odd is always 1
3 11
5 101
7 111
9 1001
11 1101

*/