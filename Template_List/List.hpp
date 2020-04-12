//==========================================================
// List with CAS insertion and iterator
//==========================================================
template<typename T>
struct Node
{
 	T data;
 	Node<T>* next;
}; 

//==========================================================

template<typename T>
class List
{
public:

	List();
	~List();

	void push_back(const T& value);
	void pop_back();
	void display();
	void loud_display();
	void push_front(const T& value);
	void pop_front();

private:
	Node<T>* head;
	Node<T>* tail;
};

//==========================================================

template<typename T>
List<T>::List():
	head(nullptr),
	tail(nullptr)
{
	std::cout << "List constructed\n";
}

//==========================================================

template<typename T>
List<T>::~List()
{
	std::cout << "List destructed\n";
}

//==========================================================

template<typename T>
void List<T>::push_back(const T& value)
{
	Node<T>* temp = new Node<T>;
	temp->data = value;
	temp->next = nullptr;

	if(head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}

//==========================================================

template<typename T>
void List<T>::push_front(const T& value)
{
	Node<T>* temp = head;
	head = new Node<T>;
	head->data = value;
	head->next = temp;

	// list with the only one element
	if(tail == nullptr)
		tail = head;
}

//==========================================================

template<typename T>
void List<T>::pop_back()
{
	// empty list
	if (head == nullptr)
    {
        throw std::out_of_range("Can't pop from empty list");
    }

    // list with the only one element
    if(head == tail)
    {
    	delete head;
    	head = nullptr;
    	tail = nullptr;
    	return;
    }

	Node<T>* temp = head;
	while(temp->next != tail)
	{
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = nullptr;
}

//==========================================================

template<typename T>
void List<T>::pop_front()
{
	// empty list
	if (head == nullptr)
    {
        throw std::out_of_range("Can't pop from empty list");
    }

    // list with the only one element
    if(head == tail)
    {
    	delete head;
    	head = nullptr;
    	tail = nullptr;
    	return;
    }

    Node<T>* temp = head->next;
    delete head;
    head = temp;
}

//==========================================================

template<typename T>
void List<T>::display()
{
	Node<T>* temp = head;

	while(temp != nullptr)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

//==========================================================

template<typename T>
void List<T>::loud_display()
{
	Node<T>* temp = head;

	while(temp != nullptr)
	{
		std::cout << temp->data << "\t" << temp << "\t" << temp->next << "\t" << head << "\t" << tail;
		std::cout << std::endl;
		temp = temp->next;
	}
}

//==========================================================



