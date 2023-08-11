#include <bits/stdc++.h>

using namespace std;

void Josh(vector<int> person, int k, int gun_man)
{

    if (person.size() == 1)
    {
        cout << person[0] << endl;
        return;
    }

    // find the index of first person which will die
    int to_be_killed = (gun_man + k) % person.size();

    // remove the first person which is going to be killed
    person.erase(person.begin() + to_be_killed);

    // recursive call for n-1 persons
    Josh(person, k, to_be_killed);
}

int main()
{
    int n = 5; // specific n and k  values for original
                // josephus problem
    int k = 3;
    k--;             // (k-1)th person will be killed
    int gun_man = 0; // The index where the person which will die

    vector<int> person;
    // fill the person vector
    for (int i = 1; i <= n; i++)
    {
        person.push_back(i);
    }

    Josh(person, k, gun_man);
    return 0;
}