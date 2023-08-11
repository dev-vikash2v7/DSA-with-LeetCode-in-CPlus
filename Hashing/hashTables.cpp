#include <bits/stdc++.h>

using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; // list 1 , index 0 , list 2 ,index 1...

public:
    bool const isEmpty();
    int hashFunction(int key);
    void insert(int key, string value);
    void remove(int key);
    string search(int key);
    void printTable();
};

bool const HashTable ::isEmpty()
{
    int sum = 0;

    for (int i = 0 ; i < hashGroups; i++)
    {
        cout << table[i].size() << endl;;  
        sum += table[i].size();
    }

    return !sum;
};

int HashTable ::hashFunction(int key)
{
    return key % hashGroups; // key:906, return 6
};

void HashTable ::insert(int key, string value)
{
    int hashKey = hashFunction(key);

    cout << "insert at ";
    cout << hashKey << endl;

    auto &cell = table[hashKey];
    auto bItr = begin(cell);

    bool keyExists = false;

    while (bItr != end(cell))
    {
        if (bItr->first == key)
        {
            keyExists = true;
            cout << "[Warning] Key exits . value replaced from " << bItr->second << " -> " << value<<endl;
            bItr->second == value;
            break;
        }
        bItr++;
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
};

void HashTable ::remove(int key)
{
    int hashKey = hashFunction(key);

    cout << "remove at ";
    cout << hashKey << endl;

    auto &cell = table[hashKey];
    auto bItr = begin(cell);

    bool keyExists = false;

    while (bItr != end(cell))
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[Success] Item Removed \n";
            break;
        }
        bItr++;
    }

    if (!keyExists)
    {
        cout << "[warning] key does not exist!!!!! \n";
    }
};

void HashTable ::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {

        if (table[i].size() == 0)
            continue;

        auto bItr = table[i].begin();

        while (bItr != table[i].end())
        {
            cout << "[Info] key : " << bItr->first << " , value : " << bItr->second << endl;
            bItr++;
        }
    }
};

string HashTable ::search(int key){
    int hashKey = hashFunction(key);

    cout << "search\n";
    cout << hashKey << endl;

    auto &cell = table[hashKey];
    auto bItr = begin(cell);

    bool keyExists = false;

    while (bItr != end(cell))
    {
        if (bItr->first == key)
        {
            keyExists = true;
            cout << "[Success] Item find \n" ;
            return  bItr->second ;
        }
        bItr++;
    }

    if (!keyExists)
    {
        cout << "[warning] key does not exist!!!!! \n";
    }
};

int main()
{

    HashTable ht; 

    if(ht.isEmpty()){
        cout << "empty table\n";
    }
    else{
        cout << "not empty table\n";
    }


ht.insert(231 , "vikash");
ht.insert(241 , "tob");
ht.insert(133 , "bob");
ht.insert(248 , "sandy");
ht.insert(836 , "lomy");
ht.insert(130 , "nick");
ht.insert(430 , "pick");
ht.insert(130 , "dick");

ht.printTable();


// ht.remove(430 );
// ht.remove(130 );
// ht.remove(930 );

// ht.printTable();

 if(ht.isEmpty()){
        cout << "empty table\n";
    }
    else{
        cout << "not empty table\n";
    }
    return 0;
}