#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int a  = 5 ;
   int* ptr = &a; // dynamically allocates memory
   int* ptr1 = new int(a); // dynamically allocates memory
   int* ptr2 = nullptr; // dynamically allocates memory

// int* arr = new int[5]; // Dynamically allocate an array of 5 integers
// delete[] arr;  

// cout << *ptr <<endl;
// cout << *ptr1 <<endl;
// cout <<( *ptr2 )<<endl;

// delete ptr;            // releases the allocated memory
// delete ptr1;            // releases the allocated memory

// cout << *ptr <<endl;
// cout << *ptr1 <<endl;


int arr[] = {10, 20, 30};
int* ptr4 = arr;
cout << *ptr4 << endl; // Outputs 20, the next element in the array
cout << *(ptr4 + 1); // Outputs 20, the next element in the array
cout << *(ptr4 + 2); // Outputs 20, the next element in the array
cout << *(ptr4 + 3); // Outputs 20, the next element in the array

    return 0;
}