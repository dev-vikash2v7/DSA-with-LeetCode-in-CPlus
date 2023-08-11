#include <iostream>

#define right 0
#define left 1
#define up 2
#define down 3

using namespace std;

const int row = 3, col = 4;

// void print_spiral(int m[row][col]  ){
//     int l = 0 , r = col - 1 ;
//     int t = 0 , b = row - 1 ;

//     while (l <= r && t <= b)
//     {
// // cout << t << " , " << l << "   " << b << " , " << r << endl;

//       for( int col = l ; col <= r ; col++){
//           cout << m[ t ][col] << " ";
//       }
//     //   cout << endl ;

//       t++;

//        for( int row = t ; row <= b ; row++){
//           cout << m[ row ][r]  << " ";
//       }
//     //   cout << endl ;

//       r--;

//       if( !(l <= r && t <= b) ) break ;

//        for( int col = r ; col >= l ; col--){
//           cout << m[ b ][col]  << " ";
//       }
//     //   cout << endl ;

//       b--;

//        for( int row = b ; row >= t  ; row--){
//           cout << m[ row ][l] << " ";
//       }
//     //   cout << endl ;

//       l++;

//     }

// };

void print_spiral(int m[row][col])
{
  int t = 0, b = row - 1;
  int l = 0, r = col - 1;

  int state = right;

  while (l <= r && t <= b)
  {
    if (state == right)
    {
      for (int col = l; col <= r; col++)
      {
        cout << m[t][col] << " ";
      }
      t++;
      state = down;
    }

  else  if (state == down)
    {
      for (int row = t; row <= b; row++)
      {
        cout << m[row][r] << " ";
      }
      r--;
      state = left;
    }

  else  if (state == left)
    {
      for (int col = r; col >= l; col--)
      {
        cout << m[b][col] << " ";
      }

      b--;
      state = up;
    }

   else if (state == up)
    {
      for (int row = b; row >= t; row--)
      {
        cout << m[row][l] << " ";
      }

      l++;
      state = right;
    }



  }
}

int main()
{
  int matrix[row][col] = {{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}};

  print_spiral(matrix);
  return 0;
}