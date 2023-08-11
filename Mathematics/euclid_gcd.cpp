#include <bits/stdc++.h>

using namespace std;

void gcd(int a ,  int b)
{
    if( a == 0){
        cout <<"gcd " << b << endl;
        return ;
    }
    gcd(b % a , a) ;

    
}

int main()
{
    int a  = 24,  b = 60 ;
    gcd(a , b);

    return 0;
}
/*
gcd => highest common factor

16 , 22

16 => 2 * 2 * 2 * 2
22 => 2 * 11
gcd => 2

by Euclid's gcd =>
 gcd(a, b)=> gcd(a - b , b) => gcd(a - 2b , b) , where a> b
 gcd(a , b) => gcd(b , a%b) => continue till a%b != 0

16 ) 22 
     16
    ---
     6  )   16 
            12
        ---------
           4 )  6 
                4
            -------
                2 )  4 
                     4
                    ----
                     0

gcd = 2

11 ) 17
    11
    ==
    6   ) 11 
          6
        ---- 
         5 ) 6
             5
             ---
             1 ) 5
                 5
                ---
                0 ) 1


  12 => 2 2 3
  24 => 2 2 2 3 
  gcd(12)

*/