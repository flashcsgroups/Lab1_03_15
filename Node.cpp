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
