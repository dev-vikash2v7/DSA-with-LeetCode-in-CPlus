#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    // *(b+3) = ' ' ; //referce to index 3
    // a[3] = ' ';

    char str[] = "this ,( is a ) & string!";
    char *symbol = str;

    symbol = strtok(str, " ");
    cout << symbol;

    while ((symbol = strtok(NULL, " ")) != NULL)
    {
        cout << symbol << endl;
    }
    cout << "\nx at end is not is " << str << endl;

    return 0;
}