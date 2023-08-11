#include <iostream>
#include <string.h>

using namespace std;

// c-style palindrome
// bool c_palindrome(char s[])
// {
//     char *front = s, *back = s;

//     while (*back != '\0') {   back++;}//move pointer to last character
//     --back;

//     while (front < back) //pointer have not met or crossed
//     {
//          cout << *front << " - "<< *back << endl;
//         if (*front != *back)
//             return false;

//         --back;
//         ++front;
//     };
// }

// bool c_palindrome(char s[])
// {
//     char *front = s, *back = s + strlen(s)-1;
//     while (front < back && *front == *back) //pointer have not met or crossed77 
//     {
//         --back;
//         ++front;
//     };
//     return front >= back;
// }

// bool c_palindrome(char s[])
// {
//     char *front = s, *back =s + strlen(s)-1;
//     while (front < back) //pointer have not met or crossed
//     {
//          cout << *front << " - "<< *back << endl;
//         if (*front != *back)
//             return false;
//         --back;
//         ++front;
//     };
// }
bool stl_palindrome(string s)
{
    string::iterator front=s.begin() ;
    string::iterator back = s.end()-1;

   while (front < back) //pointer have not met or crossed
    {
         cout << *front << " - "<< *back << endl;

        if (*front != *back)
            return false;

        --back;
        ++front;
    };
    return true;
}



int main()
{
    char a[] = "saras";

    if (stl_palindrome(a))
        cout << "it is palidrome\n"
             << endl;
    else
        cout << "not palidrome\n"
             << endl;
    return 0;
}