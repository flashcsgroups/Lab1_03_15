enum errors {outOfRange, doesNotExist};

template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* previous;

    Node(T data, Node* previous, Node* next)
    {
        this->data = data;
        this->previous = previous;
        this->next = next;
    }
};

template <typename T>
class List
{
public:
    List()
    {
        first = 0;
        last = 0;
        length = 0;
    }

    ~List()
    {
        clear();
    }

    void addFirst(T element)
    {
        Node<T>* node = new Node<T>(element, 0, first);
        if(first)
            first->previous = node;
        first = node;
        if(!last)
            last = node;
        length++;
    }

    void addLast(T element)
    {
        Node<T>* node = new Node<T>(element, last, 0);
        if(last)
            last->next = node;
        last = node;
        if(!first)
            first = node;
        length++;
    }

    int getLength()
    {
        return length;
    }

    T getOnIndex(int index)
    {
        if(!first)
            throw doesNotExist;
        if(index >= length)
            throw outOfRange;
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        return current->data;
    }

    List<T>* reverse()
    {
        List<T>* reversed = new List<T>();
        Node<T>* current = first;
        while(current!=0)
        {
            reversed->addFirst(current->data);
            current = current->next;
        }
        return reversed;
    }

    void clear()
    {
        Node<T>* current = first;
        while(current)
        {
            Node<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        first = 0;
        last = 0;
        length = 0;
    }

    void setOnIndex(int index, T data)
    {
        if(index >= length)
            throw outOfRange;
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        current->data = data;
    }

    List<T>* copy()
    {
        List<T>* temp = new List<T>();
        Node<T>* current = first;
        while(current)
        {
            temp->addLast(current->data);
            current = current->next;
        }
        return temp;
    }
private:
    Node<T>* first;
    Node<T>* last;
    int length;
};
