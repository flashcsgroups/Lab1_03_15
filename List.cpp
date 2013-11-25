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
        length++;
    }

    void addLast(T* element)
    {
        Node<T>* node = new Node<T>(*element, last, 0);
        last = node;
        length++;
    }

    void addAfter(T* element, int index)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->getNext();
        Node<T>* node = new Node<T>(*element, current, current->getNext());
        if(node->getNext())
            node->getNext()->getPrevious() = node;
        else
            last = node;
        node->getPrevious()->getNext() = node;
        length++;
    }

    void addAfter(T* element, Node<T>* after)
    {
        if(!exists(after))
            throw "fail";
        Node<T>* node = new Node<T>(*element, after, after->getNext());
        if(node->getNext())
            node->getNext()->getPrevious() = node;
        else
            last = node;
        node->getPrevious()->getNext() = node;
        length++;
    }

    void addBefore(T* element, int index)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->getNext();
        Node<T>* node = new Node<T>(*element, current->getPrevious(), current);
        node->getNext()->getPrevious() = node;
        if(node->getPrevious())
            node->getPrevious()->getNext() = node;
        else
            first = node;
        length++;
    }

    void addBefore(T* element, Node<T>* before)
    {
        if(!exists(before))
            throw "fail";
        Node<T>* node = new Node<T>(*element, before->getPrevious(), before);
        node->getNext()->getPrevious() = node;
        if(node->getPrevious())
            node->getPrevious()->getNext() = node;
        else
            first = node;
        length++;
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
            current = current->getNext();
        return current->getData();
    }

    bool exists(Node<T>* node)
    {
        Node<T>* current = first;
        while(current)
        {
            if(current==node)
                return true;
            current = current->getNext();
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

    void clear()
    {
        Node<T>* current = first;
        while(current)
        {
            Node<T>* toDelete = current;
            current = current->getNext();
            delete toDelete;
        }
        first = 0;
        last = 0;
        length = 0;
    }

    void setOnIndex(int index, T data)
    {
        if(index >= length)
            throw "fail";
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->getNext();
    }
private:
    Node<T>* first;
    Node<T>* last;
    int length;
};
