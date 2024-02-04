#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
         unordered_map<int,int> set ; 
         vector<int> points ; 

    RandomizedSet() {    }
    
    bool insert(int val) {

       if(set.find(val) != set.end()) return false;

        points.push_back(val);
        set[val] = points.size() - 1;

        return true;
    }
    
    bool remove(int val) {
                if(set.find(val) == set.end()) return false;

                int indexToRemove = set[val];
                int lastValue = points.back();

                // change last value to indexToRemove val and remove the last
                points[indexToRemove] = lastValue ;
                points.pop_back();

                set[lastValue] = indexToRemove;
                set.erase(val);

                return true;

    }
    
    int getRandom() {
        return points[rand() % points.size()];
    }
};


int main()
{
     RandomizedSet* obj = new RandomizedSet();

  bool param_1 = obj->insert(1);
  bool param_2 = obj->remove(2);
  bool param_3 = obj->insert(2);
  int param_4 = obj->getRandom();
  bool param_5 = obj->remove(5);
  bool param_6 = obj->insert(6);
  int param_7 = obj->getRandom();
  bool param_8 = obj->insert(1);

  bool param_9 = obj->remove(2);
  bool param_10 = obj->remove(6);
  bool param_11 = obj->insert(2);
  bool param_12 = obj->remove(1);

  int param_13 = obj->getRandom();


  cout << param_1<<endl;
  cout << param_2<<endl;
  cout << param_3<<endl;
  cout << param_4<<endl;
  cout << param_5<<endl;
  cout << param_6<<endl;
  cout << param_7<<endl;
  cout << param_8<<endl;

  cout << param_9<<endl;
  cout << param_10<<endl;
  cout << param_11<<endl;
  cout << param_12<<endl;
  cout << param_13<<endl;

    return 0;
}