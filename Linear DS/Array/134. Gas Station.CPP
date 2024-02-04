#include <iostream>
#include <vector>
using namespace std;

   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
            int total_remaining_gas  =  0 ;
            int current_remaining_gas  =  0 ;
            int n = gas.size();
            int start_index = 0 ; 

            for (int i = 0; i < n; i++) {

                total_remaining_gas += gas[i] - cost[i];
                current_remaining_gas += gas[i] - cost[i];

                if(current_remaining_gas < 0){
                  current_remaining_gas = 0 ;
                  start_index = i + 1 ; 
                }
            };

            return total_remaining_gas >= 0 ?  start_index : -1 ;
    }


int main()
{
    

vector<int> gas  = {1,5,3,2,2};
vector<int> cost  = {3,4,5,1,2};
cout <<  canCompleteCircuit(gas , cost) << endl;


    return 0;
}