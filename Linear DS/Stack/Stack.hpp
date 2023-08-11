#include <iostream>

using namespace std;

class Stack
{
    int size = 0;
    int top = -1;
    int *arr = NULL;

public:
    int is_Empty();
    int is_Full();
    int push(int data);
    int pop();
    void show();
    int stackTop() { return arr[top]; };
    int stackBottom() { return arr[0]; };
    Stack(int size);
    ~Stack() { delete[] arr; };
};

Stack ::Stack(int size)
{
    this->size = size;
    arr = new int[size];
}

void Stack ::show()
{
    cout << "showing list : \n";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Stack ::push(int data)
{
    if (!is_Full())
    {
        arr[++top] = data;
        return 1;
    }
    return 0;
};
int Stack ::pop()
{
    if (!is_Empty())
        return arr[top--];
    return -1;
};

int Stack ::is_Empty()
{
    if (top < 0)
        return 1;
    return 0;
}

int Stack ::is_Full()
{
    if (top == size - 1)
        return 1;
    return 0;
}