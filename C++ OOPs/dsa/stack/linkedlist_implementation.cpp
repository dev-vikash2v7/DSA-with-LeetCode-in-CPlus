#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;

    Node(int d):data(d) , next(nullptr){}
};

class Stack
{
private:
    /* data */
    Node* top ;

public:
    Stack() : top(nullptr){};

   void push(int data){

    Node *node = new Node(data);

   node->next = top;
   top = node;

    }


   void pop(){

    if(isEmpty()){
            cout << "Stack Underflow" << endl;
            return ;
    }

    Node *temp = top ;
    top = top->next ;
    delete temp;

    }

   bool isEmpty(){
    return !top;
    }

   int peek(){
    if(isEmpty()){
        cout << "No Elements" <<endl;
        return -1;
    }

    return top->data;

    }

    void display(){

Node *temp = top;

     while (temp!=nullptr)
     {
        cout << temp->data << " " ;
        temp=temp->next;
     }

     cout<<endl;
     
    }

     ~Stack() {
        while (!top)
        {
        delete top;
        top = top->next;
        }
        
    }
};



int main()
{

Stack s1;

s1.push(3);
s1.push(2);
s1.push(9);
s1.push(0);

s1.display();
cout << s1.peek()<<endl;

s1.pop();
s1.pop();
s1.pop();
s1.pop();
s1.pop();

s1.display();
// cout << s1.peek()<<endl;

    return 0;
}