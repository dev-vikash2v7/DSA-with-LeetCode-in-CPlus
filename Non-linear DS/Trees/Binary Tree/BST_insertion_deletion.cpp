#include <iostream>
using namespace std;

struct Node
{
    int data;

    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
    };
};

class Tree
{
public:
    Node *deleteNode(Node *root, int key)
    {

        if (root == NULL)
        {
            cout << "no data found in tree\n";
            return NULL;
        }
        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // find the element

            //         case 1 : no child
            if (not root->left && !root->right)
            {
                cout << "no child " << root->data << endl;

                delete root;
                return NULL;
            }
            // case 2 : one child

            // 2.1 : if only left child
            else if (root->left && !root->right)
            {
                //             # if only left child :  delete node and return root.left
                cout << "only left child " << root->data << endl;

                Node *temp = root->left;
                delete root;
                return temp;
            }
            // 2.2 : if only right child
            else if (!root->left && root->right)
            {
                //             # if only right child :  delete node and return root.right
                cout << "only right child " << root->data << endl;

                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                // case 3 : both child

                //predecessor
                // int max_left = max_tree(root->left);
                // cout << "both child " << max_left << endl;
                // root->data = max_left;
                Node *iPre = inOrderPre(root);
                cout << "both child " << root->data << endl;

                root->data = iPre->data ;
                root->left = deleteNode(root->left,  iPre->data);


                //successor
                // int min_right = min_tree(root->right);
                // cout << "both child " << root->right << endl;
                // root->data = min_right;
                // root->right = deleteNode(root->right, min_right);
                //  Node *iPost = inOrderPre(root);
                // root->data = iPost->data ;
                // root->right = deleteNode(root->right,  iPre->data);
            }
        }
    }

    int max_tree(Node *root)
    {

        while (root && root->right)
        {
            root = root->right;
        }
        return root->data;
    };

    Node* inOrderPre(Node *root)
    {
        root = root->left;

        while (root->right)
        {
            root = root->right;
        }
        return root;
    };



    int min_tree(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root->data;
    };

        Node* inOrderPost(Node *root)
    {
        root = root->right;

        while (root->left)
        {
            root = root->left;
        }
        return root;
    };

    Node *insert(Node *root, int key)
    {
        if (root == NULL)
        {
            return (new Node(key));
        }
        else if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }
        else
        {
            cout << "same key not allowed";
            return root;
        }

        return root;
    }

    void preOrder(Node *root)
    {

        if (root)
        {
            preOrder(root->left);
            cout << root->data << " ";
            preOrder(root->right);
        }
        // cout << endl;
    }
};

int main()
{

    Node *root = NULL;

    Tree tree;

    root = tree.insert(root, 30);
    root = tree.insert(root, 28);
    root = tree.insert(root, 40);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 5);
    root = tree.insert(root, 25);
    root = tree.insert(root, 22);
    root = tree.insert(root, 27);
    root = tree.insert(root, 24);

    tree.preOrder(root);
    cout << endl;
    // cout <<endl << tree.max_tree(root)<<endl;
    // cout <<endl << tree.min_tree(root);

    // root = tree.deleteNode(root , 13);
    // root = tree.deleteNode(root , 1);
    // root = tree.deleteNode(root , 3);

    // root = tree.deleteNode(root , 3);
    // root = tree.deleteNode(root , 13);

    // root = tree.deleteNode(root, 15);
    root = tree.deleteNode(root, 20);

    tree.preOrder(root);
    cout << endl;

    return 0;
}

/*
case 1 : no child
            # delete node and return NULL

case 2 : one child
            # if only left child :  delete node and return root.left
            # if only right child :  delete node and return root.right

case 3 : both child

            # find min in right subtree copy the value in targated value and delete the copied node from right-subtree
            # find max in left subtree copy the value in targated value and delete the copied node from left-subtree




*/