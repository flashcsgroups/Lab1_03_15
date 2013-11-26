#include "Node.cpp"

#include <iostream>

enum errors {outOfRange, doesNotExist};

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

    void addAfter(T* element, int index)
    {
        if(index >= length)
            throw outOfRange;
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        Node<T>* node = new Node<T>(*element, current, current->next);
        if(node->next)
            node->next->previous = node;
        else
            last = node;
        node->previous->next = node;
        length++;
    }

    void addAfter(T* element, Node<T>* after)
    {
        if(!exists(after))
            throw doesNotExist;
        Node<T>* node = new Node<T>(*element, after, after->next);
        if(node->next)
            node->next->previous = node;
        else
            last = node;
        node->previous->next = node;
        length++;
    }

    void addBefore(T* element, int index)
    {
        if(index >= length)
            throw outOfRange;
        Node<T>* current = first;
        for(int iterator = 0; iterator < index; iterator++)
            current = current->next;
        Node<T>* node = new Node<T>(*element, current->previous, current);
        node->next->previous = node;
        if(node->previous)
            node->previous->next = node;
        else
            first = node;
        length++;
    }

    void addBefore(T* element, Node<T>* before)
    {
        if(!exists(before))
            throw doesNotExist;
        Node<T>* node = new Node<T>(*element, before->previous, before);
        node->next->previous = node;
        if(node->previous)
            node->previous->next = node;
        else
            first = node;
        length++;
    }

    T getFirst()
    {
        return *(first->data);
    }

    T getLast()
    {
        return *(last->data);
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
