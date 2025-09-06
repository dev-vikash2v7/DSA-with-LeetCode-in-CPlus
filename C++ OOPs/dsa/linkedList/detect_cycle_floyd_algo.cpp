#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
    Node *next  ;
    int data  ;

    Node(int data  ) : data(data) , next(nullptr){}
};

class LinkedList {
  Node *head  = nullptr; 

    public:

    void insertAtEnd(int data){

        Node* node = new Node(data );

        if(head == nullptr){
            head  = node;
        }
        else{

             Node *temp = head ;

               while (temp->next != nullptr)
                        temp = temp->next;
                        
            temp->next = node;


        }
    }
  
    void display(){

        Node *temp = head ;

        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout <<endl;
        
    }
    void cycle(int pos){

        Node *temp = head ;
        Node *temp2 = head ;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

      while (pos != 0)
    {
        pos--;
        temp2 = temp2->next;
    }

    if(!temp2){
        cout << "index out of range" <<endl;
        return;
    }


    temp->next = temp2;
    
    
      
        
    }

    void detect(){

       Node *slow = head ;
        Node *fast = head ;

while (fast  && fast->next )
{
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
        cout<<"have cycle at "<< slow->data << endl;
        return ;
    }
}

        cout<<"no cycle" << endl;


    }


};
int main()
{
    LinkedList l1;

    l1.insertAtEnd(3);
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);
    l1.insertAtEnd(79);
    l1.insertAtEnd(70);



    
    l1.display();
   

l1.cycle(0);


    // l1.display();
l1.detect();


    return 0;
}