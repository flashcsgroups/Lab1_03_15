template <typename T>
class Node
{
public:
	Node(T data, Node* previous, Node* next)
	{
	    this->data = &data;
	    this->previous = previous;
	    this->next = next;
	}

	T getData()
	{
	    return *data;
	}

	Node* getPrevious()
	{
	    return previous;
	}

	Node* getNext()
	{
	    return next;
	}
private:
    T* data;
    Node* next;
    Node* previous;
};
