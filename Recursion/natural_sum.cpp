#include <iostream>

using namespace std;

int natural_sum(int n){
    if(n==1) return 1;

    return n+natural_sum(n-1);

}
int main()
{
cout << natural_sum(5)<<endl;
return 0;
}
