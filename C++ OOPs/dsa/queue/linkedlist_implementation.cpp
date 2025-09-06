#include <iostream>
#include <vector>
using namespace std;


struct Node
{
    /* data */
    int data ;
    Node *next;
    
    Node(int d):data(d),next(nullptr){};
};

class Queue
{
private:
 

    Node *front ;
    Node *rear ;


public:
    Queue() : front(nullptr) , rear(nullptr){};

   void enqueue(int data){
       
      Node *node = new Node(data);

        if(!front && !rear){
            front = rear = node;
        }
        else{
            node->next = rear;
            rear = node;
        }

    }


   void dequeue(){

    if(isEmpty()){
            cout << "Stack Underflow" << endl;
    }
    Node *temp = rear;

    //only one
    if(!temp->next){
        delete temp;
        front = rear = nullptr;
        return;
    }

    while (temp->next != front)
    {
        temp = temp->next ;

    }

    temp->next = nullptr;
    delete temp->next;
    front = temp;

    }

   int isEmpty(){
        return !front ;
    }



    int getFront() {
        if (!isEmpty()) {
            return front->data;
        }
        cout << "Queue is empty\n";
        return -1;  
    }

    int getRear() {
        if (!isEmpty()) {
            return rear->data;
        }
        cout << "Queue is empty\n";
        return -1;
    }

    void reverse(Node *temp){

        if(!temp){
            return;
        }

        reverse(temp->next);
    }

    void display(){

        if(!front) {
            cout<<"No elements\n";
            return;

        }

        // cout << front->data << " " <<rear->data;

      reverse(rear);
        cout<<endl;
    }

     ~Queue() {
        delete front,rear;
    }
};



int main()
{

Queue s1;

s1.enqueue(3);
s1.enqueue(2);
s1.enqueue(9);
s1.enqueue(0);

s1.display();
// cout << s1.getFront()<<endl;
// cout << s1.getRear()<<endl;

// s1.dequeue();

// s1.enqueue(96);

// s1.dequeue();
// s1.dequeue();

s1.dequeue();
s1.dequeue();
s1.dequeue();
s1.dequeue();


s1.display();

    return 0;
}