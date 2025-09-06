#include <iostream>
#include <vector>
using namespace std;

struct item
{
    int priority;
    int value ;

      item(/* args */){};



};


class PriorityQueue
{
private:
    
    int index = -1;
    item pr[1000] ;

public:

    PriorityQueue(/* args */){};

    void enque(int data , int priority){
        index++;
        pr[index].value = data;
        pr[index].priority = priority;
    };

    int peak(){

        int highestPriority = INT16_MIN;
        int ind = -1;

        for(int i = 0 ; i <= index ; i++){

            //
            if(highestPriority < pr[i].priority){
                highestPriority = pr[i].priority;
                ind = i ;
            }

// If priority is same choose  the element with the highest value
            else if(highestPriority == pr[i].priority && ind >  -1){
                if( pr[ind].value < pr[i].value ){
                    ind = i;
                }
            }
        }

        return ind ;
    }


int isEmpty(){
    return index == -1;
}
    int deque(){

        if(isEmpty()){
            cout << "Under flow"<<endl;
            return -1;
        }
        int highestPriotrityInd = peak();

        int data = pr[highestPriotrityInd].value;

                for(int i = highestPriotrityInd ; i < index ; i++){
                        pr[i]  = pr[i+1];
                }

                index--;

                return data;
    };

    void display(){

PriorityQueue temp = *this ;

while (!temp.isEmpty())
{
   cout << temp.deque() << " ";
}
cout << endl;

    }


};





int main()
{
    PriorityQueue q;

    q.enque(3 , 6);
    q.enque(1 , 2);
    q.enque(3 , 1);
    q.enque(8 , 5);
    q.enque(5 , 2);

    q.display();

    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    q.display();


    return 0;
}