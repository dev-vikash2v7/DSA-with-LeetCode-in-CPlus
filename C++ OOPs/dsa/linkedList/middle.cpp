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
    void middle(){

         if (!head) {
           cout << "List is empty" << std::endl;
            return;
        }

        Node *slow  = head ;
        Node *fast  = head ;


        while (fast != nullptr && fast->next != nullptr )
        {
            slow = slow->next;
            fast = fast->next->next;

          
        }

cout << slow->data << endl;
        
    }


};
int main()
{
    LinkedList l1;

    l1.insertAtEnd(3);
    l1.insertAtEnd(5);
    // l1.insertAtEnd(7);
    // l1.insertAtEnd(79);
    // l1.insertAtEnd(70);

    
    l1.display();
   

l1.middle();




    return 0;
}