#include <iostream>

using namespace std;

const int r = 3, c = 5;

void spiral_order(int matrix[r][c])
{
    int row_start = 0, row_end = r - 1;
    int col_start = 0, col_end = c - 1;

    while (row_start <= row_end && col_start <= col_end)
    {

        // left to right
        cout << "\nafter : left to right\n";
        for (int col = col_start; col <= col_end; col++)
            cout << matrix[row_start][col] << " ";

        // up to down
        cout << "\nafter : up to down\n";
        row_start++;
        for (int row = row_start; row <= row_end; row++)
            cout << matrix[row][col_end] << " ";

        // left to right
        cout << "\nafter : left to right\n";

        col_end--;

        // cout << "\ncccccccccooooo : " << col_end << " // " << col_start << endl;

       if ((col_end - 1) != row_start)
            for (int col = col_end; col >= col_start; col--)
                cout << matrix[row_end][col] << " ";
        

        // down to up
        row_end--;

        cout << "\nafter : down to up\n";

     if ((row_end - 1) != col_start)
        for (int row = row_end; row >= row_start; row--)
            cout << matrix[row][col_start] << " ";

        col_start++;
    }
}
int main()
{

    // int arr[r][c] = {{1, 20, 7}, {20, 5, 2}, {12, 32, 98}};
    int arr[r][c] = {{6, 6, 2, 28, 2}, {12, 26, 3, 28, 7}, {22, 25, 3, 4, 23}};
    spiral_order(arr);

    return 0;
}

/*
{1, 20, 7}
{20, 5, 2}
{12, 32, 98}

1 20 7
2 98

*/
