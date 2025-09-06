#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    /* data */
    int *arr;
    int size ;
    int rear , front ;

public:
    Queue(int s){
        arr = new int[s];
        rear = -1;
        front = -1;
    };

   void push(int data){
        if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = data ;
            return;
        }
        if( (rear+1)%size   == front){
            cout << "Stack Overflow" << endl;
            return ;
        }

        else {
                rear = (rear+1)%size;
        }
      
        arr[rear] = data ;

    }

   void pop(){

    if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return;
    }

    if(rear == (front+1)% size){
        rear = front = -1;
    }
    else{
        front  = (front+1) % size;
    }


    }

   int isEmpty(){
        return front == -1 && rear == -1;
    }



    int getFront() {
        if (!isEmpty()) {
            return arr[front];
        }
        cout << "Queue is empty\n";
        return -1;  
    }

    int getRear() {
        if (!isEmpty()) {
            return arr[rear];
        }
        cout << "Queue is empty\n";
        return -1;
    }

    void display(){

        for(int i = front ;i<= rear ;i++){
            cout << arr[i] <<" ";
        }
        cout<<endl;
    }

     ~Queue() {
        delete[] arr;
    }
};



int main()
{

Queue s1(5);

s1.push(3);
s1.push(2);
s1.push(9);
s1.push(0);

s1.display();
// cout << s1.getFront()<<endl;
// cout << s1.getRear()<<endl;

// s1.pop();

// s1.display();

    return 0;
}