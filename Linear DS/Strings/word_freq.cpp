#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string text, char del)
{
    vector<string> result;
    string temp = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == del)
        {
            result.push_back(temp);
            temp = "";
            continue;
        }
        temp += text[i];
    }
    return result;
}

class freq{
    public:
    string word;
    int count = 1;
    
    void show();
    int findItem(string word);

}
;
int freq :: findItem(string word){
    int size = arr.size() ;
    for(int i = 0 ; i <size ; i++){

    };
}

int main()
{
    string text = "a horse a horse";
    vector<string> words = split(text, ' ');

    int size = words.size() ;
    freq arr[size];

    for(int i = 0 ; i <size ; i++){
        if( words[i] ){

        }
    }

    return 0;
}