#include <iostream>
#include <list>

using namespace std;

void display(list<string> &l)
{
    list<string>::iterator iter;
    int i = 0;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter << " ";
        i++;
    }
    cout << endl<<endl;
};

void display(list<int> &l)
{
    list<int>::iterator iter;
    int i = 0;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter << " ";
        i++;
    }
    cout << endl<<endl;
};

template <class T>
void input(list<T> &l)
{
    T element;

    list<int>::iterator itr;
    for (itr = l.begin(); itr != l.end(); itr++) // l.end() => Returns an iterator pointing to the past-the-end element in the sequence:
    {
        cin >> *itr;
    }
};

int main()
{
       list<int>list1 ; //0 length list
    list1.push_back(5);
    list1.push_back(3);
    list1.push_back(2);
    list1.push_front(2);

    list<string> list2 = {"ab" ,  "cd" , "ef"}; // 5  length list
    display(list1);
    display(list2);

    // removes elements from list
    //  list2.pop_back();
    //  list2.pop_front();
    //  list2.remove(2);

    // sort the list
    // list2.sort();
    // display(list2);

    // list<int> list3(5); // 5  length list
    // input(list3);

    // display(list3);

    // cout << "after merging : \n ";
    // list3.merge(list2);
    // display(list3);

    // cout << "after reversing : \n";
    // list3.reverse();
    // display(list3);

    // swapping
    //  list<string> first(3, "first");
    // list<string> second(5, "second");

    // display(first);
    // display(second);

    // cout << "after swapping : \n";
    // first.swap(second);
    // display(first);
    // display(second);
    return 0;
}
/*
 */
