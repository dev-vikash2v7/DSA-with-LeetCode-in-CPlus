#include <iostream>
#include <vector>

using namespace std;

template <class T>
void display(vector<T> &vec)
{
    cout << "displaying this vector\n" ; 
    int size = vec.size();
cout << "size is : " <<size <<endl ;
    for (int i = 0; i < size; i++)
    {
        cout << "vec[" << i << "] = " << vec.at(i)<<endl;
    }
    cout <<endl;
};

template <class T>
void input(vector<T> &vec1, int n)
{
    T element;

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        vec1.push_back(element);
    }
};

int main()
{

   
    // vector<float> vec0 ; //0 length vector

    //  vector<char> vec1(4) ; //4 length vector
    //  vec0.push_back('b');

    // vector<float> vec2(6,349) ; //6 length vector of value 349 in each index

    vector<float> vec3 = {3 , 5, 2 ,6};
vector<float> vec4(vec3);

 // int n;
    // cout << "enter size of vector : ";
    // cin >> n;
    // input(vec1, n);
    // vec1.pop_back(); // removes the last element
    display(vec3);

// vector<float> :: iterator iter = vec1.begin();
// //refers to 3rd index 
// vec1.insert(iter+3 ,10 , 6969); //iter -> 0 index , iter+1 -> 1th index , iter + 3 -> 3rd index

//       display(vec1);
    return 0;
}
/*
template < class T, class Alloc = allocator<T> > class vector; // generic template

++ Vector --
        Vectors are sequence containers representing arrays that can change in size.

* Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

* Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.

* Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

* Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.

Member functions
(constructor)
Construct vector (public member function )
(destructor)
Vector destructor (public member function )
operator=
Assign content (public member function )
________________
Iterators:

begin
Return iterator to beginning (public member function )

end
Return iterator to end (public member function )

rbegin
Return reverse iterator to reverse beginning (public member function )

rend
Return reverse iterator to reverse end (public member function )

cbegin
Return const_iterator to beginning (public member function )

cend
Return const_iterator to end (public member function )

crbegin
Return const_reverse_iterator to reverse beginning (public member function )

crend
Return const_reverse_iterator to reverse end (public member function )

-----------------------------------------

Vector is better for frequent insertion and deletion, whereas Arrays are much better suited for frequent access of elements scenario. Vector occupies much more memory in exchange for managing storage and growing dynamically, whereas Arrays are a memory-efficient data structure.
*/
