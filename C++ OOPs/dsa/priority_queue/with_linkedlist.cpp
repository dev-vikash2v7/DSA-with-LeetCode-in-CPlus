#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int priority;
    int value ;
    Node *next; 

    Node(int d, int p) : priority(p) , value(d) , next(NULL){}



};


class PriorityQueue
{
private:
    
    Node *head = NULL;

public:

    PriorityQueue(/* args */){};

    void enque(int data , int priority){
        Node *node =  new Node(data , priority);

        if(isEmpty()){
            head = node;
            return ;
        }

        if(head->priority  < priority){
            node->next = head ;
            head = node ;
            return ;
        }

        Node *temp  = head ; 
        
        while (temp->next && temp->next->priority  > priority)
        {
            /* code */
            temp = temp->next;
        } 


        node->next = temp->next;
        temp->next = node;
        
    };

    int peakNode(){

 if(isEmpty()){
            cout << "Under flow"<<endl;
            return -1;
        }

        return head->value  ;
    }


int isEmpty(){
    return head == NULL;
}
    int deque(){

        if(isEmpty()){
            cout << "Under flow"<<endl;
            return -1;
        }
        Node *temp  = head ;

       
        head = head->next;

        delete temp;
        
                return head->value;
    };

    void display(){

Node *temp = head ;

while (temp)
{
   cout << temp->value << " ";
   temp = temp->next;
}
cout << endl;

    }


};





int main()
{
    PriorityQueue q;

     // Create a Priority Queue
  

    q.enque(3 , 6);
    q.enque(4  ,  8);
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