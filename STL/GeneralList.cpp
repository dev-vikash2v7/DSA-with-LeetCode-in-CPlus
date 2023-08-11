#include <iostream>
using namespace std;
template <class Type>
class GLinkedList;

template <class Type>
class GListNode
{
public:
    bool isatom; // flag that indicates whether the node is an atomic element or a pointer to a list .
    GListNode<Type> *next = NULL;
    // either a data value of a pointer a sublist. the union feature enables us to allocate only the space needed by the larger of these two types
    union
    {
        Type data;
        GListNode<Type> *list;
    };
    friend class GLinkedList<Type>;
};

template <class Type>
class GLinkedList
{
public:
    GLinkedList<Type>(){
        root->next = NULL ;
        root->data = 78 ;
    };
    GListNode<Type> *root ;
    int length;

    void show();
    void insert_data(int pos, Type data);
    GListNode<Type> *insert_list(int pos, GLinkedList<Type> L);

    void insert_at_end(Type data);
    GListNode<Type> *clear(GListNode<Type> *);

    ~GLinkedList<Type>()
    {
        clear(root);
        root = NULL;
    }
};
template <class Type>
void GLinkedList<Type>::show()
{
    GListNode<Type> *temp = root;
    cout << "[ ";
    if (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " ]" << endl;
};

template <class Type>
void GLinkedList<Type>::insert_at_end(Type data)
{
    GListNode<Type> *head = new GListNode<Type>();
    GListNode<Type> *temp = root;
    head->data = data;
    head->next = NULL;

    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = head ;
};


template <class Type>
GListNode<Type> *GLinkedList<Type>::clear(GListNode<Type> *node)
{
    if (node != NULL)
    {
        clear(node->next);
        // free(node);
        delete node;
    }
    root = NULL;
    return root;
}


int main()
{
    GLinkedList<char> final, temp1, temp2, temp3, temp4, temp5;
    GListNode<char> *temp;

    if (temp == NULL)
    {
        cout << "space fulled\n";
        exit(0);
    }
    final.root =  new GListNode<char>() ;
    final.insert_at_end('a');
     final.insert_at_end( 'b');
    final.insert_at_end( 'c');
    //    final.insert_data( -2 );

    final.show();

    // head = ptr.insert_data(0, 69659, head);
    // head = ptr.insert_data_begin(999, head);

    // head = ptr.clear(head);
    // head = ptr.delete_at(1, head);
    // head = ptr.delete_at(0, head);

    // cout << ptr.find_item(1987, head);
    // ptr.show(head);

    return 0;
}

// feature of general list class

/*
 * a retrieval func to search a specific list
 * a general retrieval func to search the whole structure
 * insertion function for both simple data and lists
 * a showlist function to depict the list structure
 */