#include "Node.cpp"

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

    void addFirst(T* element)
    {
        Node<T>* node = new Node<T>(*element, 0, first);
        first = node;
    }

    void addLast(T* element)
    {
        Node<T>* node = new Node<T>(*element, last, 0);
        last = node;
    }

    void addAfter(T* element, int index)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        Node<T>* node = new Node<T>(*element, current, current->next);
        if(node->next)
            node->next->previous = node;
        node->previous->next = node;
    }

    void addAfter(T* element, Node<T>* after)
    {
        if(!exists(after))
            throw "fail";
        Node<T>* node = new Node<T>(*element, after, after->next);
        if(node->next)
            node->next->previous = node;
        node->previous->next = node;
    }

    void addBefore(T* element, int index)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        Node<T>* node = new Node<T>(*element, current->previous, current);
        if(node->next)
            node->next->previous = node;
        node->previous->next = node;
    }

    void addBefore(T* element, Node<T>* before)
    {
        if(!exists(before))
            throw "fail";
        Node<T>* node = new Node<T>(*element, before->previous, before);
        node->next->previous = node;
        if(node->previous)
            node->previous->next = node;
    }

    T getFirst()
    {
        return first->getData();
    }

    T getLast()
    {
        return last->getData();
    }

    T getOnIndex(int index)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        return current->getData();
    }

    bool exists(Node<T>* node)
    {
        Node<T>* current = first;
        while(current)
        {
            if(current==node)
                return true;
            current = current->next;
        }
        return false;
    }

    List<T>* reverse()
    {
        List<T>* reversed = new List<T>();
        Node<T>* current = first;
        while(current)
        {
            reversed->addFirst(current);
            current = current->getNext();
        }
    }
private:
    Node<T>* first;
    Node<T>* last;
    int length;
};
