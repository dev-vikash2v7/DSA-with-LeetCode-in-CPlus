#include <iostream>
using namespace std;

int max_(int a, int b) { return a ? a > b : b; };

class Node
{
    public :

    int data, height = 1;

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
    Node *getBalancedRoot(Node *root, int key)
    {
        int bf = getBalancedFactor(root);

        // case 1 : left left
        if (bf > 1 && key < root->left->data)
        {
            // right rotation
            return RightRotate(root);
        }

        // case 2 : left right => bf > 1 and key > root.left.data
        else if (bf > 1 && key > root->left->data)
        {
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }

        // case 3 : right right => bf < -1 and key > root.right.data
        else if (bf < -1 && key > root->right->data)
        {
            // left rotation
            return LeftRotate(root);
        }

        // case 4 : right left => bf < -1 and key < root.right.data
        else if (bf < -1 && key < root->right->data)
        {
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }

        return root;
    };


// #        z
// # ============================
// # t1            y
// # =============================
// #          t2      x

    Node *LeftRotate(Node *root)
    {
            Node *z = root ;
            Node *y = z->right ;
            Node *t2 = y->left ;

            //perform rotation
            y->left = z ;
            z->right = t2 ;

            //update height
            z->height = 1+ max_( getHeight(z->left) , getHeight(z->right));
            y->height = 1+ max_( getHeight(y->left) , getHeight(y->right));

            return y ;
    }
// #                z
// # ============================
// #       y            t1
// # =============================
// #   x       t2      

    Node *RightRotate(Node *root)
    {
            Node *z = root ;
            Node *y = z->left ;
            Node *t2 = y->right ;

            //perform rotation
            y->right = z ;
            z->left = t2 ;

            //update height
            z->height = 1+ max_( getHeight(z->left) , getHeight(z->right));
            y->height = 1+ max_( getHeight(y->left) , getHeight(y->right));

            return y ;
    }

    int getBalancedFactor(Node *root)
    {
        return root == NULL ? 0 : getHeight(root->left) - getHeight(root->right);
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
            return root ;
        }
        root->height = 1 + max_(getHeight(root->left), getHeight(root->right));

        return getBalancedRoot(root, key);
    }

    void preOrder(Node *root)
    {

        if (root)
        {
            cout << root->data << " ";
            cout << "(" << getBalancedFactor(root) << ") ";
            preOrder(root->left);
            preOrder(root->right);
        }
        // cout << endl;
    }

    int getHeight(Node *root)
    {
        // return  root == NULL  ? 0 :  1 + max_(  getHeight(root->left)  , getHeight(root->right)   );
        return root == NULL ? 0 : root->height;
    }
};

int main()
{

    Node *root = NULL;

    Tree tree;

    root = tree.insert(root, 1);
    root = tree.insert(root, 2);
    root = tree.insert(root, 4);
    root = tree.insert(root, 5);
    root = tree.insert(root, 7);
    root = tree.insert(root ,0 );
    root = tree.insert(root ,3 );
    root = tree.insert(root ,8 );

    tree.preOrder(root);

    return 0;
}



/*
                 
                       2
              1                   5 
        0                    4          7 
                         3                   8
         
                                             



            30
    20            40
                       50
                              60


                40
            30
        20
    10
case 1 : right right : bf < -1 and data > root.right.key
       z
============================
t1            y
=============================
         t2      x
=============================
                      t4

 ======    left rotation on z  ==========

            y
=============================
    z            x
===============================
t1      t2           t4




case 2 : right left  : bf < -1 and data < root.right.key
       z
============================
t1            y
=============================
         t2      x
=============================
    t4

======    right  rotation  on y ==========

            z
=============================
    t1             t2
===============================
              t4      y
=============================
                        x


======    left  rotation  on z ==========

            t2
=============================
    z             y
===============================
t1       t4           x
=============================




case 3 : left left   : bf > 1 and data < root.left.key

                    z(2)
=====================================
            y             t4
 ======================================
        x       t3
======================================
    t1     t2


======    right  rotation  on  z ==========

            y
=============================
    x               z
===============================
t1      t2       t3       t4
=============================





case 4 : left right  : bf > 1 and data > root.left.key

                    z(2)
=====================================
            y             t4
 ======================================
        t1       x
======================================
            t2      t3


======    left  rotation  on  y ==========

                z
=============================
         x               t4
===============================
      y      t3
=============================
  t1    t2

======    right  rotation  on  z ==========

            x
=============================
    y               z
===============================
 t1      t2       t3       t4
=============================

*/