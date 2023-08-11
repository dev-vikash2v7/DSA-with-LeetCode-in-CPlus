#include <iostream>
#include <cstring>

using namespace std;

void Tower_of_Hanoi(int n, char* src,  char* dest ,char* helper)
{
    if (n==1) {
    cout << src << "->" << dest << endl;
        return ;
    } 

    Tower_of_Hanoi(n-1 ,src ,  helper , dest  );
        cout << src << "->" << dest << endl;
    Tower_of_Hanoi(n-1 ,helper , dest ,  src  );
}

int main()
{
    int n = 3;
    
    
    char * src =  strdup("src");
    char * helpler = strdup("helper");
    char * dest = strdup("dest");


    Tower_of_Hanoi(n, src,  dest ,helpler);
    return 0;
}