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
        front = 0;
    };

   void push(int data){
        if(rear + 1>= size){
            cout << "Stack Overflow" << endl;
            return ;
        }
      
        arr[++rear] = data ;

    }
   void pop(){

    if(isEmpty()){
            cout << "Stack Underflow" << endl;
    }
    front++;
    }

   int isEmpty(){
        return front  > rear;
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
cout << s1.getFront()<<endl;
cout << s1.getRear()<<endl;

s1.pop();

s1.display();

    return 0;
}