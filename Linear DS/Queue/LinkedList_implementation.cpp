#include <iostream>

using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
    Node(int d) : data(d){};
};

class Queue
{

    Node *front = NULL;
    Node *top = NULL;
public:
    void enqueue(int data)
    {
        Node *node = new Node(data);

        if (front == NULL)
        {
            front = top = node;
        }
        else
        {
            top->next = node;
            top = node;
        }
    }
    int dequeu()
    {
        if (isEmpty())
        {
           cout << "Queue Underflow!!\n";
           return -1;
        }

        Node *todelete = front ;

        int d = todelete->data;

        front = front->next ;

        delete (todelete );

        return  d;
    }
    void show()
    {
        if(top==NULL) return ;

        Node *temp = front ;

        while(temp){
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        cout<<endl;
    };

    int getFront()
    {
        if (isEmpty())
        {
           cout << "No element!!\n";
           return -1;
        }
        return front->data ;
    }
    int peek()
    {
        if (isEmpty())
        {
           cout << "No element!!\n";
           return -1;
        }
        return top->data ;
    }

    bool isEmpty(){
        return front == NULL;
    }

};

int main()
{
    Queue q ;
    q.enqueue(40);
    q.enqueue(74);
    q.enqueue(45);
    q.enqueue(24);
    q.enqueue(41);
    q.enqueue(41);
    q.enqueue(69);
q.show();
cout << q.peek()<< endl;
cout << q.getFront() << endl;

cout << q.dequeu() << endl;
cout << q.dequeu() << endl;


q.show();

    return 0;
}