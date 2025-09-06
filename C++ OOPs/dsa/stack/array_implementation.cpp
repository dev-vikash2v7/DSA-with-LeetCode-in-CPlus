#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    /* data */
    int *arr;
    int size ;
    int top ;

public:
    Queue(int s){
        arr = new int[s];
        top = -1;
        size = s ;
    };

   void enqueue(int data){
        if(top + 1 >= size){
            cout << "Stack Overflow" << endl;
            return ;
        }
        arr[++top] = data ;

    }
   void dequeue(){

    if(isEmpty()){
            cout << "Stack Underflow" << endl;
    }
top--;
        // int a =  arr[top--];
    }

   int isEmpty(){

    if(top  == -1){
            return 1 ;
        }
        return 0;
    }

   int peek(){
    if(isEmpty()){
        cout << "No Elements" <<endl;
        return -1;
    }

    return arr[top];

    }

    void display(){

        for(int i = 0 ;i<= top ;i++){
            cout << arr[i] <<" ";
        }
        cout<<endl;
    }

     ~Stack() {
        delete[] arr;
    }
};



int main()
{

Stack s1(5);

s1.push(3);
s1.push(2);
s1.push(9);
s1.push(0);

s1.display();
cout << s1.peek()<<endl;

s1.pop();

s1.display();
cout << s1.peek()<<endl;

    return 0;
}