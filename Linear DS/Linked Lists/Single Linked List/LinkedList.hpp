#define show(message) cout << #message << endl

using namespace std;
template <class Type>
class LinkedList;


/////////////////////////////////////////////////////class List Node ///////////////////////////////////////////////////

template <class Type>
class ListNode
{
public:
    Type data;
    ListNode *next;
    friend class LinkedList<Type>;
};

///////////////////////////////////////////////////// class Linked List ///////////////////////////////////////////////////
template <class Type>
class LinkedList
{
public:
    int length = 0;

    ListNode<Type> *root = NULL;
    LinkedList() {  };      // default constructor
    LinkedList(const LinkedList &);            // copy constructor
    LinkedList &operator=(const LinkedList &); // = operator

    void display();
    int count_length(ListNode<Type> *node);
    void clear();
    void copylist(ListNode<Type> *&newlist, ListNode<Type> *&oldlist);

    void insertAtBegin(Type data);
    void insertAtEnd(Type data);
    void insertAt(Type data, int pos);
    void insertAfterNode(ListNode<Type> *prevNode, Type data);

    void remove_at(int pos);
    void remove_at_end();
    void release_node(ListNode<Type> *&node);

    ~LinkedList() { release_node(root); };
};

//////////////////////////////////copy consructor and operator overloading///////////////////////////////////////////////////
template <class Type>
void LinkedList<Type>::copylist(ListNode<Type> *&newlist, ListNode<Type> *&oldlist)
{
    show("in copylist" );
    newlist = NULL;
    if (oldlist != NULL)
    {
        newlist = new ListNode<Type>();
        newlist->data = oldlist->data;
        oldlist = oldlist->next;
        copylist(newlist->next, oldlist->next);
    }
};

// copy constructor
template <class Type>
LinkedList<Type>::LinkedList(const LinkedList &list)
{
    show("in copy constructor" );
    copylist(root, list.root);
};

// operator =
template <class Type>
LinkedList<Type> &LinkedList<Type>::operator=(const LinkedList &list)
{
    show("in = operaetor");
    if (this != &list)
    {
        release_node(root); // to stop memory leak
        copylist(root, list.root);
    }
    return *this;
};

///////////////////////////////////////////////////// retrival ///////////////////////////////////////////////////
template <class Type>
void LinkedList<Type>::display()
{
    ListNode<Type> *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class Type>
int LinkedList<Type>::count_length(ListNode<Type> *node)
{
    if (node == NULL)
    {
        return 0;
    }
    length = 1 + count_length(node->next);
    return length;
}

///////////////////////////////////////////////////// deletion ///////////////////////////////////////////////////

template <class Type>
void LinkedList<Type>::clear()
{
    release_node();
    root = NULL;
};

template <class Type>
void LinkedList<Type>::remove_at(int pos)
{
    if(pos > 0 && pos < length){
        
    }
    else{
        show("bad parameter");
    }
}

template <class Type>
void LinkedList<Type>::remove_at_end()
{
    length = count_length(root) ;
    if (root != NULL)
    {
        ListNode<Type> *temp = root;
        int i = 0;
        while (i != length - 2)
        {
            temp = temp->next;
            i++;
        }
        temp->next = NULL;
    }
    else
    {
        cout << "empty list\n";
    }
}

template <class Type>
void LinkedList<Type>::release_node(ListNode<Type> *&node)
{
    while (node != NULL)
    {
        release_node(node->next);
        delete node;
    }
}

///////////////////////////////////////////////////// insertion ///////////////////////////////////////////////////

template <class Type>
void LinkedList<Type>::insertAtBegin(Type data)
{
    ListNode<int> *node = new ListNode<int>();
    node->next = root;
    node->data = data;
    root = node;
}

template <class Type>
void LinkedList<Type>::insertAtEnd(Type data)
{
    ListNode<Type> *temp = root;
    ListNode<int> *node = new ListNode<int>();

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node->data = data;
    node->next = NULL;
    temp->next = node;
}

template <class Type>
void LinkedList<Type>::insertAfterNode(ListNode<Type> *prevNode, Type data)
{
    ListNode<int> *node = new ListNode<int>();

    node->data = data;
    node->next = prevNode->next;
    prevNode->next = node;
}

template <class Type>
void LinkedList<Type>::insertAt(Type data, int pos)
{
    if (pos == 0)
    {
        insertAtBeggin(data);
    }
    else if (pos > 0 && pos < length)
    {
        ListNode<Type> *temp = root;
        ListNode<int> *node = new ListNode<int>();

        int i = 0;
        while (i != pos - 1)
        {
            temp = temp->next;
            i++;
        }
        node->data = data;
        node->next = temp->next;

        temp->next = node;
    }
    else
    {
        cout << "index out of range!\n";
    }
}
