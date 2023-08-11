#include <iostream>

using namespace std;

/*
find the longest subarray with at most k zeros

*/
void max_consecutivee_ones(string arr, int n, int k)
{
    int max_ones = 0;
    int start_flip = 0;
    int end = 0;
    int flip = 0;

    for (; end < n; end++)
    {
        if (arr[end] == '0')
        {
            flip++;
        }

        // unflip previous 0 because flipping limit exced
        while (flip > k)
        {
            if (arr[start_flip] == '0')
            {
                flip--;
            }
            start_flip++;
        }
        max_ones = max_ones > (end - start_flip + 1) ? max_ones : (end - start_flip + 1);
        printf("%d %d %d %d\n", end, start, max_ones, flip);
    }
    cout << max_ones << endl;
}
int main()
{
    string bin = "1100101101";
    int n = bin.size();
    int k = 2;

    max_consecutivee_ones(bin, n, k);

    return 0;
}

/*
11--1011

end , start , max_ones , flip , k = 2
0     0        1        0
1     0       2         0
2     0       3          1
3     0       4          2
4     0        5           2
5    0,1,2,3    3,5              3,2
6     3         4,5            2
7      3        5,5         2
8      3,4      5            3,2
9      4        6             2



*/