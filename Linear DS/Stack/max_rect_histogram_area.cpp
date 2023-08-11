#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> res)
{
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

/*
brute force approch
O(N*N)
*/
// int getMaxArea(vector<int> hist)
// {
//     int n = hist.size();
//     int maxArea = 0;

//     for (int current = 0; current < n; current++)
//     {

//         int left = current, right = current;

//         while (hist[left] >= hist[current])
//         {
//             left--;
//         }
//         while (hist[right] >= hist[current])
//         {
//             right++;
//         }

//         left++;
//         right--;

//         if (left < 0)
//         {
//             left = 0;
//         }

//         int area = hist[current] * (right - left + 1);

//         if (area > maxArea)
//         {
//             maxArea = area;
//         }
//         cout << left << " " << right << "  " << area << endl;
//     }

//     return maxArea;
// };

vector<int> prevSmaller(vector<int> arr)
{
    int n = arr.size();
    vector<int> res;
    vector<int> st;

    for (int i = 0; i < n; i++)
    {

        /*if the height is :
                        greater that arr[st.top()] push it into the stack
                        less than arr[st.top] keep poppint the elements until arr[i] >= arr[s.top]
                      */
        while (!st.empty() && arr[i] <= arr[st.back()])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(st.back());
        }
        st.push_back(i);
    }
    return res;
}

vector<int> nextSmaller(vector<int> arr)
{

     int n = arr.size();
    vector<int> res;
    vector<int> st;

    for (int i = n-1; i >= 0  ; i--)
    {
        while (!st.empty() && arr[i] >= arr[st.back()])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            res.push_back(n);
        }
        else
        {
            res.insert(res.begin() , st.back());
        }
        st.push_back(i);
    }
    return res;
}

int getMaxArea(vector<int> hist)
{
    int n = hist.size();
    int maxArea = 0;
    // vector<int> prevSm = prevSmaller(hist);
    vector<int> nextSm = nextSmaller(hist);
    // show(prevSm);
    show(nextSm);
    // for (int current = 0; current < n; current++)
    // {
    //     int area = hist[current] * (nextSm[current] - prevSm [current] + 1);

    //     if (area > maxArea)
    //     {
    //         maxArea = area;
    //     }
    // }

    return maxArea;
};

int main()
{
    vector<int> res;

    vector<int> hist = {4, 2, 1, 5, 6, 3, 2, 4, 2};

    int area = getMaxArea(hist);
    cout << area << endl;
    return 0;
}