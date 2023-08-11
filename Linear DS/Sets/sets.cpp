#include <iostream>
#include <vector>

using namespace std;

class Set
{
private:
    /* data */
public:
    Set();
    Set(const Set& );

    bool is_member(int );
    bool insert(int );
    bool remove(int );
    bool empty( );
    int size();

    void show(ostream & , char [] = "");
    bool extract(int& ); // take the arbitary member
    Set operator -(const Set&);

    ~Set();
};




int main()
{
    Set result;
    
return 0;  
}
