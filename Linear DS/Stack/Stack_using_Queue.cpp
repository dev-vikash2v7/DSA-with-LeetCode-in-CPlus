#include <iostream>
#include <queue>

using namespace std;

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    void push(int d)
    {
        q1.push(d);
    }
    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.push(q1.back());
                q1.pop();
            }
        }
        q1.pop();
        // swap
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    };
};

int main()
{

    return 0;
}