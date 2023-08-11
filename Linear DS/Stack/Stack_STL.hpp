template <class Type>
class Stack
{
private:
    int length ;
    Type *stack_data;
    int count = -1;

public:
Stack(int size) : length(size) {
    stack_data = new Type[length];
}
~Stack(){
    delete [] stack_data;
}
    void push(Type);
    Type pop();
    bool isEmpty();
    bool isOverflow();
    Type getTop();
    Type getBottom();
    void show();
};

template <class Type>
void Stack<Type>::push(Type data)
{
    if (!isOverflow())
    {
        
        stack_data[++count] = data;
    }
}

template <class Type>
Type Stack<Type>::pop()
{
    if (!isEmpty())
    {
        return stack_data[count--];
    }
}

template <class Type>
bool Stack<Type>::isEmpty()
{
    if (count < 0)
    {
       std::cout << "Stack is Empty . No pop operation possibble!!\n";
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
bool Stack<Type>::isOverflow()
{
    if (count == length)
    {
       std:: cout << "Stack is Full . No push operation possibble!!\n";
        return true;
    }
    else
    {
        return false;
    }
}
template <class Type>
Type Stack<Type>::getBottom()
{
    if (count >= 0)
    {
        return stack_data[0];
    }
    else
    {
        std::cout << "stack_data is empty\n";
        return -1;
    }
}
template <class Type>
Type Stack<Type>::getTop()
{
    if (count >= 0)
    {
        return stack_data[count];
    }
    else
    {
        std::cout << "stack_data is empty\n";
        return -1;
    }
}

template <class Type>
void Stack<Type>::show()
{
    if (count >= 0)
    {
        for (int i = 0; i <= count; i++)
        {
            cout << stack_data[i] << " ";
        }
        std::cout << endl;
    }
    else
    {
        std::cout << "stack_data is empty\n";
    }
}