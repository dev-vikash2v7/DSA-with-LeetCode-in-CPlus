#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    
    int maxProfit = 0;
    int currentProfit = 0;
    int currentStock = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        currentProfit = prices[i] - currentStock;

        if(currentProfit < 0) {
            currentStock = prices[i];
            currentProfit = 0;
        }
        else{
            if(currentProfit > maxProfit)
              maxProfit = currentProfit;
        }
      
    }

    return maxProfit;
}

int main()
{
    vector<int> prices  = {3, 5, 1, 7, 4, 9, 3};
   cout <<  maxProfit(prices);

    return 0;
}