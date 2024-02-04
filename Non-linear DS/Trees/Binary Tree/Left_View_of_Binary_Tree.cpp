#include <std/>

using namespace std;

struct Node
{
    int data;

    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
        this->left = this->right  = NULL; 
    };
};


   class Tree{
public:
    int* PrintLeftViewOfTree(Node *root)
    {

        bool isLeftPrinted = false ;

        vector<int>queue ;

        queue.push(root->data);

        while (queue)
        {
            if( !isLeftPrinted){
                cout << root->data << endl;
            }
            
        }
        



       
    }

   };

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    Tree tree ;
    int *result =  tree.PrintLeftViewOfTree(root);

    // for(int i : result) cout << i << endl;
    return 0;
}



/* 

        1
    2        3

                   4 

=>LEFT VIEW =  1->2->4
*/