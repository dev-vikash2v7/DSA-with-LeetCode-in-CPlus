/*
Given an array A of size N of integers. Your task is to find the minimum and maximum
elements in the array.
*/
#include <iostream>

using namespace std;

pair<long long, long long> getMinMax(long long a[], int n)
{
    pair<long long, long long> PAIR1;

    long long min_ = 100000, max_ = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min_)
        {
            min_ = a[i];
        }
        if (a[i] > max_)
        {
            max_ = a[i];
        }
    }

    PAIR1.first = min_;
    PAIR1.second = max_;
    return PAIR1;
}
int main()
{
    long long a[7] = {4, 3, 8, 4, 2, 99, 21};
    int n = 7;
    pair<long long, long long> PAIR1 = getMinMax(a, n);

    cout << PAIR1.first << endl;
    cout << PAIR1.second << endl;
    return 0;
}