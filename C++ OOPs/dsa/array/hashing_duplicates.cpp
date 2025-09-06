#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int func(vector<int>& nums) {

unordered_map<int,int>dup ; 
vector<int> res;

for (int i = 0; i < nums.size(); i++) {


    if(dup[nums[i]] == -1){
        res.push_back(nums[i]);
        dup[nums[i]] = -2;
    }
    else if(dup[nums[i]] == -2){
        continue;
    }
    else{
        dup[nums[i]] = -1;
    }
}
    for(int num : res){
        cout << num << endl;
    }
}
int func2(vector<int>& nums) {

unordered_map<int,int>dup ; 
vector<int> res;

for(int num : res){
    dup[num]++;
    }

for (const auto pair : dup) {


    if(pair.second > 1 ){
        res.push_back(pair.first);
    }
  
}
    for(int num : res){
        cout << num << endl;
    }
}


int main()
{
    

vector<int> nums  = {3, 5, 1, 7, 4, 9, 3 , 1 , 5,  3 , 1 , 5 , 3 };
func(nums);

    return 0;
}