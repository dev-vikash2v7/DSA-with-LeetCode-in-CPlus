#include <iostream>
#include <map>
// #include <string.h>

using namespace std;

// template <class T>
// void display(list<T> &l)
// {
    
//     list<string>::iterator iter;
//     int i = 0;

//     for (iter = l.begin(); iter != l.end(); iter++)
//     {
//         cout << *iter << " ";
//         i++;
//     }
//     cout << endl<<endl;
// };

// template <class T>
// void input(list<T> &l)
// {
//     T element;

//     list<int>::iterator itr;
//     for (itr = l.begin(); itr != l.end(); itr++) // l.end() => Returns an iterator pointing to the past-the-end element in the sequence:
//     {
//         cin >> *itr;
//     }
// };

int main()
{
   //Maps are associative containers that store elements formed by a combination of a key value and a mapped value,

    map<string , int>m1;
    m1["roll_no"] = 135;
    m1["clas"] = 1;
    m1["sdf"] = 37;

    m1.insert({ {"dfaa" , 564} , {"ggrdg" , 53544} });

    map<string,int> :: iterator itr;

    for( itr = m1.begin() ; itr != m1.end() ; itr++){
        cout << (*itr).first << " = " << (*itr).second <<  endl ;
    }
    cout << "size = " << m1.size() <<endl;
    cout << "max size = " << m1.max_size() <<endl;
    cout << "empty = " << m1.empty() <<endl;
    cout << "size = " << m1.size() <<endl;
    return 0;
}
/*
 */
